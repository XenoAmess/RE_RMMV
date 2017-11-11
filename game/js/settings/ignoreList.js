ignoreList = [
    "img/system/Window.png"
];


$ignoreListObject = {};
for (var i in ignoreList) {
    $ignoreListObject[ignoreList[i]] = null;
    // console.log(ignoreList[i]);
}