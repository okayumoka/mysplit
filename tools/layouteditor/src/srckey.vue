
<template>
	<div :class="[className, {'selected': selected}]" @click="onClick">
		<div>
			{{name}}
		</div>
	</div>
</template>

<style scoped>
.srckey {
	display: inline-block;
	position: relative;
	width: 44px;
	height: 44px;	
	margin: 0;
	cursor: pointer;
}
.srckey div {
	display: inline-block;
	position: absolute;
	top: 2px;
	right: 2px;
	bottom: 2px;
	left: 2px;
	line-height: 40px;
	border: solid 1px gray;
	text-align: center;
	overflow: hidden;
	font-size: 12px;
	font-family: 'Consolas', monospace;
	background: white;
}
.srckey.selected div {
	background: lightgray;
}

.srckey.BS { width: 88px; }
.srckey.Tab { width: 66px; }
.srckey.Caps { width: 78px; }
.srckey.Enter { width: 98px; margin-right: 164px;  }
.srckey.LShift { width: 100px; }
.srckey.RShift { width: 120px; margin-right: 55px; }
.srckey.LCtrl { width: 66px; }
.srckey.LAlt { width: 66px; }
.srckey.Space { width: 264px; }
.srckey.RAlt { width: 66px; }
.srckey.RCtrl { width: 66px; }
.srckey.pipe { width: 66px; }
.srckey.Esc { margin-right: 44px; }
.srckey.halfm { margin-right: 22px; }
.srckey.minim { margin-right: 10px; }
.srckey.fullm { margin-right: 44px; }
</style>

<script>
module.exports = {
	props: [ 'name', 'keyCode' ],
	data: function() {
		return {
			className: 'srckey',
			selected: false,
		}
	},
	created: function() {
		this.className = 'srckey ' + this.name;
	},
	methods: {
		onClick: function() {
			let tmp = this.selected;
			this.$emit('onclick', this);
			this.selected = !tmp;
		}
	},
};
</script>


