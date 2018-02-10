
<template>
	<div id="layouteditor">
		{{title}}
		<div>
			Size: <input @keydown="onKeyDown" type="number"> x <input type="number">
		</div>
		<div>
			<srckeys ref="srckeys"></srckeys>
		</div>
		<div>
			<!-- Left -->
			<div class="keyboard">
				<div v-for="row in rowIndex" :key="row">
					<key v-for="col in colIndex" :key="col" @onclick="onClickDest"></key>
				</div>
			</div>
			<!-- Right -->
			<div class="keyboard">
				<div v-for="row in rowIndex" :key="row">
					<key v-for="col in colIndex" :key="col+10" @onclick="onClickDest"></key>
				</div>
			</div>
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
		}
	},
	created: function() {
		console.log(this.rowIndex);
	},
	methods: {
		onKeyDown: function(e) {
			console.log(e);
			console.log('0x' + e.keyCode.toString(16).toUpperCase());
		},
		onClickDest: function(destKey) {
			let selectedSrcKey = this.$refs.srckeys.getSelectedKey();
			// console.log(destKey);
			// console.log(selectedSrcKey);
			if (selectedSrcKey != null) {
				destKey.name = selectedSrcKey.name;
				destKey.keyCode = selectedSrcKey.keyCode;
			}
		},
	},
};
</script>


