
import Vue from 'vue';
import App from './app.vue';
import Key from './key.vue';
import SrcKey from './srckey.vue';
import SrcKeys from './srckeys.vue';

Vue.component('app', App);
Vue.component('key', Key);
Vue.component('srckey', SrcKey);
Vue.component('srckeys', SrcKeys);

new Vue({
	el: '#app',
	render: x => x(App)
});

