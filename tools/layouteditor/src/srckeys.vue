
<template>
	<div class="src-keyboard">
		<div class="row" style="margin-bottom: 10px;">
			<srckey key-code="0xFF" name="Esc" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="0xFF" name="F1" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="0xFF" name="F2" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="0xFF" name="F3" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="0xFF" name="F4" @onclick="onClickSrcKey" class="halfm"></srckey>
			<srckey key-code="0xFF" name="F5" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="0xFF" name="F6" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="0xFF" name="F7" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="0xFF" name="F8" @onclick="onClickSrcKey" class="halfm"></srckey>
			<srckey key-code="0xFF" name="F9" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="0xFF" name="F10" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="0xFF" name="F11" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="0xFF" name="F12" @onclick="onClickSrcKey" class="minim"></srckey>
			<srckey key-code="0xFF" name="PrtSc" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="0xFF" name="ScrLk" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="0xFF" name="Pause" @onclick="onClickSrcKey"></srckey>
		</div>
		<div class="row">
			<srckey key-code="0xFF" name="` ~" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="0xFF" name="1" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="0xFF" name="2" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="0xFF" name="3" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="0xFF" name="4" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="0xFF" name="5" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="0xFF" name="6" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="0xFF" name="7" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="0xFF" name="8" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="0xFF" name="9" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="0xFF" name="0" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="0xFF" name="- _" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="0xFF" name="= +" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="0xFF" name="BS" @onclick="onClickSrcKey" class="minim"></srckey>
			<srckey key-code="0xFF" name="Ins" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="0xFF" name="Home" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="0xFF" name="PgUp" @onclick="onClickSrcKey" class="halfm"></srckey>
			<srckey key-code="0xFF" name="Upper" @onclick="onClickSrcKey"></srckey>
		</div>
		<div class="row">
			<srckey key-code="0xFF" name="Tab" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="0xFF" name="Q" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="0xFF" name="W" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="0xFF" name="E" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="0xFF" name="R" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="0xFF" name="T" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="0xFF" name="Y" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="0xFF" name="U" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="0xFF" name="I" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="0xFF" name="O" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="0xFF" name="P" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="0xFF" name="[ {" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="0xFF" name="] }" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="0xFF" name="| \" class="pipe minim" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="0xFF" name="Del" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="0xFF" name="End" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="0xFF" name="PgDn" class="halfm" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="0xFF" name="Lower" @onclick="onClickSrcKey"></srckey>
		</div>
		<div class="row">
			<srckey key-code="0xFF" name="Caps" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="0xFF" name="A" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="0xFF" name="S" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="0xFF" name="D" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="0xFF" name="F" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="0xFF" name="G" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="0xFF" name="H" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="0xFF" name="J" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="0xFF" name="K" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="0xFF" name="L" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="0xFF" name="; :" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="0xFF" name="' ''" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="0xFF" name="Enter" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="0x00" name="----" @onclick="onClickSrcKey"></srckey>
		</div>
		<div class="row">
			<srckey key-code="0xFF" name="LShift" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="0xFF" name="Z" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="0xFF" name="X" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="0xFF" name="C" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="0xFF" name="V" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="0xFF" name="B" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="0xFF" name="N" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="0xFF" name="M" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="0xFF" name="< ," @onclick="onClickSrcKey"></srckey>
			<srckey key-code="0xFF" name="> ." @onclick="onClickSrcKey"></srckey>
			<srckey key-code="0xFF" name="/ ?" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="0xFF" name="RShift" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="0xFF" name="↑" @onclick="onClickSrcKey"></srckey>
		</div>
		<div class="row" style="margin-bottom: 10px;">
			<srckey key-code="0xFF" name="LCtrl" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="0xFF" name="LWin" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="0xFF" name="LAlt" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="0xFF" name="Space" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="0xFF" name="RAlt" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="0xFF" name="RWin" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="0xFF" name="Menu" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="0xFF" name="RCtrl" class="minim" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="0xFF" name="←" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="0xFF" name="↓" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="0xFF" name="→" @onclick="onClickSrcKey"></srckey>
		</div>
	</div>
</template>

<style>
.src-keyboard {
	font-size: 0;
}
</style>

<script>
module.exports = {
	props: [ ],
	data: function() {
		return {
		}
	},
	methods: {
		onClickSrcKey: function(clickedSrcKey) {
			this.$children.forEach(function(child) {
				if (child.hasOwnProperty('selected'))
					child.selected = false;
			});
		},
		getSelectedKey: function() {
			let children = this.$children;
			for (let i = 0; i < children.length; i++) {
				let child = children[i];
				if (child.selected) return child;
			}
			return null;
		}
	},
};
</script>


