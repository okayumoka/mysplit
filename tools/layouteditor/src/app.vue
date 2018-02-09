
<template>
	<div id="layouteditor">
		{{title}}
		<div>
			Size: <input @keydown="onKeyDown" type="number"> x <input type="number">
		</div>
		<div>
			<!-- Left -->
			<div class="keyboard">
				<div v-for="row in rowIndex" :key="row">
					<key v-for="col in colIndex" :key="col" keyCode="col"></key>
				</div>
			</div>
			<!-- Right -->
			<div class="keyboard">
				<div v-for="row in rowIndex" :key="row">
					<key v-for="col in colIndex" :key="col+10" keyCode="col"></key>
				</div>
			</div>
		</div>
	</div>
</template>

<style>
.keyboard {
	float: left;
	border: solid 1px red;
	padding-top: 5px;
	padding-left: 5px;
	margin-right: 10px;
}
</style>

<script>

let layout = require('../layouts/default.5x6.json');
console.log(layout);

module.exports = {
	data: function() {
		return {
			title: 'Layout Editor',
			colIndex: [...Array(6).keys()].map(x => x + 1),
			rowIndex: [...Array(5).keys()].map(x => x + 1),
		}
	},
	created: function() {
		console.log(this.rowIndex);
	},
	methods: {
		onKeyDown: function(e) {
			console.log(e);
			console.log('0x' + e.keyCode.toString(16).toUpperCase());
		}
	},
};
</script>


