
<template>
	<div id="layouteditor">
		{{title}}
		<div>
			Size: <input type="number"> x <input type="number">
		</div>
		<div>
			<srckeys ref="srckeys"></srckeys>
		</div>
		<layerselect ref="layerselect" initial="normal" @onchange="onChangeLayer"></layerselect>
		<div>
			<!-- Left -->
			<div class="keyboard">
				<div v-for="row in rowIndex" :key="row">
					<key v-for="col in colIndex" :key="col" :row="row" :col="col" @onclick="onClickDest"></key>
				</div>
			</div>
			<!-- Right -->
			<div class="keyboard">
				<div v-for="row in rowIndex" :key="row">
					<key v-for="col in colIndex" :key="col+10" :row="row" :col="col+colIndex.length" @onclick="onClickDest"></key>
				</div>
			</div>
		</div>

		<button @click="onClickGenerate">Generate</button>
		<a target="_blank" :href="downloadUrl" :download="downloadFilename">Download</a>
		<div>
			keymap.ino:<br>
			<textarea v-model="keymapIno" cols="30" rows="10"></textarea>
		</div>
		<div>
			Load layout from file:<br>
			<input type="file" @change="onSelectFile">
		</div>
	</div>
</template>

<style scoped>
.keyboard {
	float: left;
	border: solid 1px red;
	padding: 5px;
	margin-right: 20px;
	font-size: 0;
}
</style>

<script>

// let layout = require('../layouts/default.5x6.json');
// console.log(layout);

function generateOutputIno(keyMapList) {
	// let arrayToStr = (ary) => {
	// 	return '\t{ ' + ary.map(r => r.join(', ')).join(' },\n\t{ ') + ' }';
	// };
	let arrayToStr = (ary, index) => {
		return '\t{ ' + 
			ary.map(r => r.map(c => c.keyCodes[index]).join(', '))
			.join(' },\n\t{ ') + 
		' }';
	};
	return `// This is keymap.h for MySplit.

// JSON
// ${JSON.stringify(keyMapList)}
	
// Pro micro
#include "keycode.h"
const int keyMapLower[ROW_NUM][COL_NUM_2] = {
${arrayToStr(keyMapList, 0)}
};

const int keyMap[ROW_NUM][COL_NUM_2] = {
${arrayToStr(keyMapList, 1)}
};

const int keyMapUpper[ROW_NUM][COL_NUM_2] = {
${arrayToStr(keyMapList, 2)}
};
`;
}

function genKeyMapArray(rowMax, colMax) {
	let a = [];
	for (let i = 0; i < rowMax; i++) {
		a[i] = Array(colMax);
	}
	return a;
}

function parseSrcText(srcText) {
	let lines = srcText.split(/\n/);
	for (let i = 1; i < lines.length; i++) {
		let preLine = lines[i-1].trim();
		let jsonLine = lines[i].trim();
		if (preLine == '// JSON') {
			jsonLine = jsonLine.substr(2);
			console.log(jsonLine);
			return json = JSON.parse(jsonLine);
		}
	}
}

module.exports = {
	data: function() {
		return {
			title: 'Layout Editor',
			colIndex: [...Array(6).keys()],
			rowIndex: [...Array(5).keys()],
			currentLayerIndex: 1,
			keymapIno: '',
			downloadUrl: '',
			downloadFilename: 'empty',
			srcText: '',
		}
	},
	created: function() {
	},
	methods: {
		onClickDest: function(destKey) {
			let selectedSrcKey = this.$refs.srckeys.getSelectedKey();
			console.log(destKey);
			console.log(selectedSrcKey);
			if (selectedSrcKey != null) {
				destKey.setName(this.currentLayerIndex, selectedSrcKey.name);
				destKey.setKeyCode(this.currentLayerIndex, selectedSrcKey.keyCode);
			}
		},
		onChangeLayer: function(name, index) {
			// console.log(name + ' ' + index);
			this.currentLayerIndex = index;
		},
		onClickGenerate: function() {
			let keys = this.getKeys();

			let keyInfoList = genKeyMapArray(this.rowIndex.length, this.colIndex.length);

			keys.forEach((key) => {
				let row = key.row;
				let col = key.col;
				keyInfoList[row][col] = key.getKeyInfo();
			});

			let ino = generateOutputIno(keyInfoList);
			this.downloadAsFile(ino, 'keymap.ino', 'application/text');
			this.keymapIno = ino;
		},
		getKeys: function() {
			return this.$children.filter((child) => {
				return child.$options._componentTag == 'key';
			});
		},
		downloadAsFile: function(str, filename, mimetype) {
			let url = (window.URL || window.webkitURL).createObjectURL(new Blob([str], { 'type': mimetype }));
			this.downloadUrl = url;
			this.downloadFilename = filename;
		},
		onSelectFile: function(e) {
			let target = e.target;
			let file = target.files[0];
			let reader = new FileReader();
			reader.onload = (e) => {
				// console.log(e);
				// console.log(e.target.result);
				this.srcText = e.target.result;
				let srcJson = parseSrcText(this.srcText);
				this.applyToLayout(srcJson);
			};
			reader.readAsText(file);
		},
		applyToLayout: function(srcJson) {
			let keys = this.getKeys();
			let lower = srcJson.lower;
			let normal = srcJson.normal;
			let upper = srcJson.upper;
			console.log(srcJson);
			keys.forEach((key) => {
				let row = key.row;
				let col = key.col;
				let keyInfo = srcJson[row][col];
				key.setKeyInfo(keyInfo);
				// let keyCodes = key.keyCodes;
				// lower[row][col] = keyCodes[0] == null ? 'KC_NULL' : keyCodes[0];
				// normal[row][col] = keyCodes[1] == null ? 'KC_NULL' : keyCodes[1];
				// upper[row][col] = keyCodes[2] == null ? 'KC_NULL' : keyCodes[2];
			});
		},
	},
};
</script>


