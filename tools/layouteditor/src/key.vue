
<template>
	<div class="key" @click="onClick">
		<div>
			<span v-for="name in names">{{name}}<br></span>
		</div>
	</div>
</template>

<style scoped>
.key {
	display: inline-block;
	position: relative;
	width: 54px;
	height: 54px;	
	margin: 0;
	cursor: pointer;
}
.key div {
	display: inline-block;
	position: absolute;
	top: 2px;
	right: 2px;
	bottom: 2px;
	left: 2px;
	line-height: 16.5px;
	border: solid 1px gray;
	text-align: center;
	overflow: hidden;
	font-size: 12px;
	font-family: 'Consolas';
	background: white;
}
</style>

<script>
module.exports = {
	props: [ 'row', 'col' ],
	data: function() {
		return {
			layer: 1, // 0:lower 1:normal 2:upper
			names: ['---', '---', '---' ],	// current
			keyCodes: [null, null, null],
		}
	},
	created: function() {
		// console.log(this.keyCode);
	},
	methods: {
		onClick: function() {
			this.$emit('onclick', this);
		},
		setName: function(layer, name) {
			// this.names = [].concat(this.names);
			// this.names[layer] = name;
			this.names.splice(layer, 1, name);
		},
		setKeyCode: function(layer, keyCode) {
			this.keyCodes.splice(layer, 1, keyCode);
		},
		setLayer: function(layer) {
			this.layer = layer;
		},
	},
};
</script>


