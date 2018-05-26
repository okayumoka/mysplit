<template>
  <div id="layouteditor">
    <h1>Layout Editor</h1>
    <div class="lay-size">
      <div class="control-area">
        Size: 
        <input type="number" v-model="rowSize" @change="onChangeSize">
        x
        <input type="number" v-model="colSize" @change="onChangeSize">
      </div>
      <div class="control-area">
        <button @click="onClickRestore">Restore from File</button>
        <input type="file" ref="fileselect" class="hidden" @change="onSelectFile">
      </div>
      <div class="control-area">
        <button @click="onClickGenerate">Generate & Download</button>
        <a class="hidden" target="_blank" ref="downloadlink" :href="downloadUrl" :download="downloadFilename">Download</a>
        <textarea class="hidden" v-model="keymapIno" cols="30" rows="10"></textarea>
      </div>
    </div>
    <div>
      <srckeys ref="srckeys"></srckeys>
    </div>
    <layerselect ref="layerselect" initial="normal" @onchange="onChangeLayer"></layerselect>
    <div>
      <!-- Left -->
      <div class="keyboard">
        <div v-for="row in rowIndex" :key="row">
          <key v-for="col in colIndex" :key="col" :row="row" :col="col" @onclick="onClickDest"></key>
        </div>
      </div>
      <!-- Right -->
      <div class="keyboard">
        <div v-for="row in rowIndex" :key="row">
          <key v-for="col in colIndex" :key="col+10" :row="row" :col="col+colIndex.length" @onclick="onClickDest"></key>
        </div>
      </div>
    </div>
  </div>
</template>

<script>

function generateOutputIno(keyMapList) {
  let arrayToStr = (ary, index) => {
    return '    { ' + 
      ary.map(r => r.map(c => c.keyCodes[index]).join(', '))
      .join(' },\n    { ') + 
      ' }';
  };
  return `// This is keymap.h for MySplit.

// JSON
// ${JSON.stringify(keyMapList)}

// Pro micro
#include "keycode.h"
const int keyMapLower[ROW_NUM][COL_NUM_2] = {
${arrayToStr(keyMapList, 0)}
};

const int keyMap[ROW_NUM][COL_NUM_2] = {
${arrayToStr(keyMapList, 1)}
};

const int keyMapRaise[ROW_NUM][COL_NUM_2] = {
${arrayToStr(keyMapList, 2)}
};
`;
}

function genKeyMapArray(rowMax, colMax) {
  let a = [];
  for (let i = 0; i < rowMax; i++) {
    a[i] = Array(colMax);
  }
  return a;
}

function parseSrcText(srcText) {
  let lines = srcText.split(/\n/);
  for (let i = 1; i < lines.length; i++) {
    let preLine = lines[i-1].trim();
    let jsonLine = lines[i].trim();
    if (preLine == '// JSON') {
      jsonLine = jsonLine.substr(2);
      console.log(jsonLine);
      return json = JSON.parse(jsonLine);
    }
  }
}

module.exports = {
  data: function() {
    let rowSize = 4;
    let colSize = 7;
    return {
      rowSize: rowSize,
      colSize: colSize,
      rowIndex: [...Array(rowSize).keys()],
      colIndex: [...Array(colSize).keys()],
      currentLayerIndex: 1,
      keymapIno: '',
      downloadUrl: '',
      downloadFilename: 'empty',
      srcText: '',
    }
  },
  created: function() {
  },
  methods: {
    onChangeSize: function() {
      this.rowSize = +this.rowSize;
      this.colSize = +this.colSize;
      this.rowIndex = [...Array(this.rowSize).keys()];
      this.colIndex = [...Array(this.colSize).keys()];
      this.$forceUpdate();
    },
    onClickDest: function(destKey) {
      let selectedSrcKey = this.$refs.srckeys.getSelectedKey();
      console.log(destKey);
      console.log(selectedSrcKey);
      if (selectedSrcKey != null) {
        destKey.setName(this.currentLayerIndex, selectedSrcKey.name);
        destKey.setKeyCode(this.currentLayerIndex, selectedSrcKey.keyCode);
      }
    },
    onChangeLayer: function(name, index) {
      // console.log(name + ' ' + index);
      this.currentLayerIndex = index;
    },
    onClickRestore: function() {
      this.$refs.fileselect.click();
    },
    onClickGenerate: function() {
      let keys = this.getKeys();

      let keyInfoList = genKeyMapArray(this.rowIndex.length, this.colIndex.length);

      keys.forEach((key) => {
        let row = key.row;
        let col = key.col;
        keyInfoList[row][col] = key.getKeyInfo();
      });

      let ino = generateOutputIno(keyInfoList);
      this.downloadAsFile(ino, 'keymap.ino', 'application/text');
      this.keymapIno = ino;
      setTimeout(() => {
        console.log(this.$refs.downloadlink);
        this.$refs.downloadlink.click();
      }, 500);
    },
    getKeys: function() {
      return this.$children.filter((child) => {
        return child.$options._componentTag == 'key';
      });
    },
    downloadAsFile: function(str, filename, mimetype) {
      let url = (window.URL || window.webkitURL).createObjectURL(new Blob([str], { 'type': mimetype }));
      this.downloadUrl = url;
      this.downloadFilename = filename;
    },
    onSelectFile: function(e) {
      let target = e.target;
      let file = target.files[0];
      let reader = new FileReader();
      reader.onload = (e) => {
        this.srcText = e.target.result;
        let srcJson = parseSrcText(this.srcText);
        this.applyToLayout(srcJson);
      };
      reader.readAsText(file);
    },
    applyToLayout: function(srcJson) {
      let keys = this.getKeys();
      let lower = srcJson.lower;
      let normal = srcJson.normal;
      let upper = srcJson.upper;
      console.log(srcJson);
      keys.forEach((key) => {
        let row = key.row;
        let col = key.col;
        let keyInfo = srcJson[row][col];
        key.setKeyInfo(keyInfo);
      });
    },
  },
};
</script>

<style scoped>
#layouteditor {
  width: 1000px;
  overflow: auto;
}
.hidden {
  display: none;
}
.control-area {
  display: inline-block;
  margin: 0 10px;
}
input[type=number] {
  padding: 5px 10px;
  border: solid 1px gray;
  border-radius: 2px;
  width: 25px;
}
button {
  border: solid 1px gray;
  border-radius: 5px;
  font-size: 16px;
  padding: 5px 10px;
}
button:hover {
  cursor: pointer;
}
h1 {
  display: inline-block;
  font-size: 16px;
  margin-right: 20px;
}
.lay-size {
  display: inline-block;
  margin-bottom: 10px;
}
.keyboard {
  float: left;
  border: solid 1px gray;
  border-radius: 4px;
  padding: 5px;
  margin-right: 10px;
  font-size: 0;
}
</style>

