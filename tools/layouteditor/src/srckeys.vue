
<template>
	<div class="src-keyboard">
		<div class="row" style="margin-bottom: 10px;">
			<srckey key-code="KC_ESC " name="Esc" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="KC_F1  " name="F1" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="KC_F2  " name="F2" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="KC_F3  " name="F3" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="KC_F4  " name="F4" @onclick="onClickSrcKey" class="halfm"></srckey>
			<srckey key-code="KC_F5  " name="F5" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="KC_F6  " name="F6" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="KC_F7  " name="F7" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="KC_F8  " name="F8" @onclick="onClickSrcKey" class="halfm"></srckey>
			<srckey key-code="KC_F9  " name="F9" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="KC_F10 " name="F10" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="KC_F11 " name="F11" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="KC_F12 " name="F12" @onclick="onClickSrcKey" class="minim"></srckey>
			<srckey key-code="KC_PSCR" name="PrtSc" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="KC_SCLK" name="ScrLk" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="KC_PAUS" name="Pause" @onclick="onClickSrcKey"></srckey>
		</div>
		<div class="row">
			<srckey key-code="KC_GRAV" name="` ~" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="KC_1   " name="1 !" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="KC_2   " name="2 @" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="KC_3   " name="3 #"@onclick="onClickSrcKey"></srckey>
			<srckey key-code="KC_4   " name="4 $" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="KC_5   " name="5 %" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="KC_6   " name="6 ^" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="KC_7   " name="7 &amp;" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="KC_8   " name="8 *" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="KC_9   " name="9 (" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="KC_0   " name="0 )" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="KC_MINS" name="- _" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="KC_EQL " name="= +" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="KC_BS  " name="BS" @onclick="onClickSrcKey" class="minim"></srckey>
			<srckey key-code="KC_INS " name="Ins" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="KC_HOME" name="Home" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="KC_PGUP" name="PgUp" @onclick="onClickSrcKey" class="halfm"></srckey>
			<srckey key-code="KC_ULAY" name="Upper" @onclick="onClickSrcKey"></srckey>
		</div>
		<div class="row">
			<srckey key-code="KC_TAB " name="Tab" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="KC_q   " name="Q" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="KC_w   " name="W" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="KC_e   " name="E" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="KC_r   " name="R" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="KC_t   " name="T" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="KC_y   " name="Y" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="KC_u   " name="U" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="KC_i   " name="I" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="KC_o   " name="O" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="KC_p   " name="P" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="KC_LB  " name="[ {" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="KC_RB  " name="] }" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="KC_BSLS" name="\ |" class="pipe minim" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="KC_DEL " name="Del" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="KC_END " name="End" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="KC_PGDN" name="PgDn" class="halfm" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="KC_LLAY" name="Lower" @onclick="onClickSrcKey"></srckey>
		</div>
		<div class="row">
			<srckey key-code="KC_CAPS" name="Caps" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="KC_a   " name="A" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="KC_s   " name="S" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="KC_d   " name="D" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="KC_f   " name="F" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="KC_g   " name="G" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="KC_h   " name="H" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="KC_j   " name="J" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="KC_k   " name="K" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="KC_l   " name="L" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="KC_SCLN" name="; :" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="KC_QUOT" name="' ''" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="KC_RET " name="Enter" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="KC_NULL" name="---" @onclick="onClickSrcKey"></srckey>
		</div>
		<div class="row">
			<srckey key-code="KC_LSFT" name="LShift" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="KC_z   " name="Z" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="KC_x   " name="X" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="KC_c   " name="C" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="KC_v   " name="V" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="KC_b   " name="B" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="KC_n   " name="N" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="KC_m   " name="M" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="KC_COMM" name=", <" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="KC_DOT " name=". >" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="KC_SLSH" name="/ ?" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="KC_RSFT" name="RShift" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="KC_UP  " name="↑" @onclick="onClickSrcKey"></srckey>
		</div>
		<div class="row" style="margin-bottom: 10px;">
			<srckey key-code="KC_LCTL" name="LCtrl" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="KC_LGUI" name="LWin" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="KC_LALT" name="LAlt" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="KC_SPC " name="Space" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="KC_RALT" name="RAlt" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="KC_RGUI" name="RWin" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="KC_MENU" name="Menu" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="KC_RCTL" name="RCtrl" class="minim" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="KC_LEFT" name="←" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="KC_DOWN" name="↓" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="KC_RGHT" name="→" @onclick="onClickSrcKey"></srckey>
		</div>
		<div class="row" style="margin-bottom: 10px;">
			<srckey key-code="KC_EXLM" name="!" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="KC_AT  " name="@" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="KC_HASH" name="#" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="KC_DLR " name="$" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="KC_PREC" name="%" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="KC_CRET" name="^" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="KC_AMP " name="&amp;" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="KC_ASTR" name="*" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="KC_LPRN" name="(" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="KC_RPRN" name=")" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="KC_USCR" name="_" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="KC_PLUS" name="+" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="KC_VBAR" name="|" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="KC_TILD" name="~" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="KC_LCB " name="{" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="KC_RCB " name="}" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="KC_CLN " name=":" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="KC_DQUO" name="&quot;" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="KC_LT  " name="&lt;" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="KC_GT  " name="&gt;" @onclick="onClickSrcKey"></srckey>
			<srckey key-code="KC_QUES" name="?" @onclick="onClickSrcKey"></srckey>
		</div>
	</div>
</template>

<style scoped>
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


