
<template>
	<div id="layouteditor">
		{{title}}
		<div>
			Size: <input @keydown="onKeyDown" type="number"> x <input type="number">
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
		<div>
			keymap.ino:<br>
			<textarea v-model="keymapIno" cols="30" rows="10"></textarea>
		</div>
	</div>
</template>

<style>
.keyboard {
	float: left;
	border: solid 1px red;
	padding: 5px;
	margin-right: 20px;
	font-size: 0;
}
</style>

<script>

let layout = require('../layouts/default.5x6.json');
console.log(layout);

module.exports = {
	data: function() {
		return {
			title: 'Layout Editor',
			colIndex: [...Array(6).keys()],
			rowIndex: [...Array(5).keys()],
			currentLayerIndex: 1,
			keymapIno: 'hoge',
		}
	},
	created: function() {
	},
	methods: {
		onKeyDown: function(e) {
			console.log(e);
			console.log('0x' + e.keyCode.toString(16).toUpperCase());
		},
		onClickDest: function(destKey) {
			let selectedSrcKey = this.$refs.srckeys.getSelectedKey();
			console.log(destKey);
			console.log(selectedSrcKey);
			if (selectedSrcKey != null) {
				destKey.setName(this.currentLayerIndex, selectedSrcKey.name);
				destKey.setKeyCode(this.currentLayerIndex, selectedSrcKey.keyCode);
				// destKey.keyCodes = selectedSrcKey.keyCode;
			}
		},
		onChangeLayer: function(name, index) {
			// console.log(name + ' ' + index);
			this.currentLayerIndex = index;
		},
		onClickGenerate: function() {
			let keys = this.$children.filter((child) => {
				return child.$options._componentTag == 'key';
			});
			console.log(keys);
			console.log(keys.length);

			let genarray = () => {
				let a = [];
				for (let i = 0; i < this.rowIndex.length; i++) {
					a[i] = Array(this.colIndex.length);
				}
				return a;
			};
			let lower = genarray();
			let normal = genarray();
			let upper = genarray();

			keys.forEach((key) => {
				let row = key.row;
				let col = key.col;
				let keyCodes = key.keyCodes;
				lower[row][col] = keyCodes[0] == null ? 'KC_NULL' : keyCodes[0];
				normal[row][col] = keyCodes[1] == null ? 'KC_NULL' : keyCodes[1];
				upper[row][col] = keyCodes[2] == null ? 'KC_NULL' : keyCodes[2];
			});

			let base = `
#include "keycode.h"
const byte keyMap[ROW_NUM][COL_NUM*2] = {

};
const byte keyMapUpper[ROW_NUM][COL_NUM_2]
};
const byte keyMapLower[ROW_NUM][COL_NUM_2] = {
};
`;
			// #include "keycode.h"
			// const byte keyMap[ROW_NUM][COL_NUM*2] = {
			//   {}
			// };
			// const byte keyMapUpper[ROW_NUM][COL_NUM_2]
			// };
			// const byte keyMapLower[ROW_NUM][COL_NUM_2] = {
			// };


			console.log(normal);
		},
	},
};
</script>


