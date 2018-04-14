
<template>
	<div>
		Layer:
		<button :class="{selected:currentLayer=='lower'}" @click="onClickLayerSelect('lower')">Lower</button>
		<button :class="{selected:currentLayer=='normal'}" @click="onClickLayerSelect('normal')">Normal</button>
		<button :class="{selected:currentLayer=='upper'}" @click="onClickLayerSelect('upper')">Upper</button>
	</div>
</template>


<style scoped>
button {
	border: solid 1px darkgray;
	background: none;
	border-radius: 3px;
	font-size: 14px;
	font-family: 'Consolas', monospace;
}
button.selected {
	border: solid 1px red;
}
</style>

<script>
module.exports = {
	props: [ 'initial' ],
	data: function() {
		return {
			currentLayer: 'normal'
		};
	},
	created: function() {
		this.currentLayer = this.initial;
	},
	methods: {
		onClickLayerSelect: function(layer, button) {
			this.currentLayer = layer;
			this.$emit('onchange', this.getSelected(), this.getSelectedIndex());
		},
		getSelected: function() {
			return this.currentLayer;
		},
		getSelectedIndex: function() {
			return {
				'lower': 0,
				'normal': 1,
				'upper': 2
			}[this.currentLayer];
		},
	},
};
</script>

