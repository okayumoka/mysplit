
<template>
	<div id="layouteditor">
		{{title}}
		<div>
			Size: <input @keydown="onKeyDown" type="number"> x <input type="number">
		</div>
		<div>
			<div class="src-keyboard">
				<div class="row">
					<srckey key-code="0xFF" name="Esc" />
					<srckey key-code="0xFF" name="F1" />
					<srckey key-code="0xFF" name="F2" />
					<srckey key-code="0xFF" name="F3" />
					<srckey key-code="0xFF" name="F4" />
					<srckey key-code="0xFF" name="F5" />
					<srckey key-code="0xFF" name="F6" />
					<srckey key-code="0xFF" name="F7" />
					<srckey key-code="0xFF" name="F8" />
					<srckey key-code="0xFF" name="F9" />
					<srckey key-code="0xFF" name="F10" />
					<srckey key-code="0xFF" name="F11" />
					<srckey key-code="0xFF" name="F12" />
				</div>
				<div class="row">
					<srckey key-code="0xFF" name="` ~" />
					<srckey key-code="0xFF" name="1" />
					<srckey key-code="0xFF" name="2" />
					<srckey key-code="0xFF" name="3" />
					<srckey key-code="0xFF" name="4" />
					<srckey key-code="0xFF" name="5" />
					<srckey key-code="0xFF" name="6" />
					<srckey key-code="0xFF" name="7" />
					<srckey key-code="0xFF" name="8" />
					<srckey key-code="0xFF" name="9" />
					<srckey key-code="0xFF" name="0" />
					<srckey key-code="0xFF" name="- _" />
					<srckey key-code="0xFF" name="= +" />
					<srckey key-code="0xFF" name="BS" />
				</div>
				<div class="row">
					<srckey key-code="0xFF" name="Tab" />
					<srckey key-code="0xFF" name="Q" />
					<srckey key-code="0xFF" name="W" />
					<srckey key-code="0xFF" name="E" />
					<srckey key-code="0xFF" name="R" />
					<srckey key-code="0xFF" name="T" />
					<srckey key-code="0xFF" name="Y" />
					<srckey key-code="0xFF" name="U" />
					<srckey key-code="0xFF" name="I" />
					<srckey key-code="0xFF" name="O" />
					<srckey key-code="0xFF" name="P" />
					<srckey key-code="0xFF" name="[ {" />
					<srckey key-code="0xFF" name="] }" />
					<srckey key-code="0xFF" name="Delete" />
					<srckey key-code="0xFF" name="Delete" />
				</div>
				<div class="row">
					<srckey key-code="0xFF" name="Caps" />
					<srckey key-code="0xFF" name="A" />
					<srckey key-code="0xFF" name="S" />
					<srckey key-code="0xFF" name="D" />
					<srckey key-code="0xFF" name="F" />
					<srckey key-code="0xFF" name="G" />
					<srckey key-code="0xFF" name="H" />
					<srckey key-code="0xFF" name="J" />
					<srckey key-code="0xFF" name="K" />
					<srckey key-code="0xFF" name="L" />
					<srckey key-code="0xFF" name="; :" />
					<srckey key-code="0xFF" name="' ''" />
					<srckey key-code="0xFF" name="Return" />
				</div>
				<div class="row">
					<srckey key-code="0xFF" name="LShift" />
					<srckey key-code="0xFF" name="Z" />
					<srckey key-code="0xFF" name="X" />
					<srckey key-code="0xFF" name="C" />
					<srckey key-code="0xFF" name="V" />
					<srckey key-code="0xFF" name="B" />
					<srckey key-code="0xFF" name="N" />
					<srckey key-code="0xFF" name="M" />
					<srckey key-code="0xFF" name="< ," />
					<srckey key-code="0xFF" name="> ." />
					<srckey key-code="0xFF" name="/ ?" />
					<srckey key-code="0xFF" name="Shift" />
					<srckey key-code="0xFF" name="FN" />
					<srckey key-code="0xFF" name="" />
					<srckey key-code="0xFF" name="" />
				</div>
				<div class="row">
					<srckey key-code="0xFF" name="Alt" />
					<srckey key-code="0xFF" name="Win" />
					<srckey key-code="0xFF" name="Space" />
					<srckey key-code="0xFF" name="Win" />
					<srckey key-code="0xFF" name="Alt" />
					<srckey key-code="0xFF" name="" />
					<srckey key-code="0xFF" name="" />
					<srckey key-code="0xFF" name="" />
				</div>
			</div>
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
		}
	},
};
</script>


