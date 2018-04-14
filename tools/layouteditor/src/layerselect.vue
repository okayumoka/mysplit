<template>
	<div>
		Layer:
		<button :class="{selected:currentLayer=='lower'}" @click="onClickLayerSelect('lower')">Lower</button>
		<button :class="{selected:currentLayer=='normal'}" @click="onClickLayerSelect('normal')">Normal</button>
		<button :class="{selected:currentLayer=='upper'}" @click="onClickLayerSelect('upper')">Upper</button>
	</div>
</template>

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

<style scoped>
div {
  margin-bottom: 10px;
}
button {
	border: solid 1px gray;
	background: none;
	border-radius: 2px;
  font-size: 14px;
  padding: 5px 10px;
	font-family: 'Consolas', monospace;
  font-weight: normal;
  cursor: pointer;
}
button.selected {
  background: gray;
  color: white;
  font-weight: bold;
}
</style>

