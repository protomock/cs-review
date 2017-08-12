var TreeNode = require("./TreeNode");

function BST() {
  this.root = null;
}

var _loadArray = function(array) {
  if (!array.length) return;
  var middle = Math.floor(array.length / 2);
  var treeNode = new TreeNode(array[middle]);

  treeNode.left = _loadArray(array.slice(0, middle));
  treeNode.right = _loadArray(array.slice(middle + 1, array.length));

  return treeNode;
};

var _findMin = function(root) {
  if (!root) return;
  var min = _findMin(root.left);
  if (!min) min = root;
  return min;
};

var _findMax = function(root) {
  if (!root) return;
  var max = _findMax(root.right);
  if (!max) max = root;
  return max;
};

BST.prototype = {
  constructor: BST,
  loadFromArray: function(array) {
    this.root = _loadArray(array);
  },
  findMin: function() {
    return _findMin(this.root);
  },
  findMax: function() {
    return _findMax(this.root);
  }
};

module.exports = BST;
