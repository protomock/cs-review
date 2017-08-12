var expect = require("chai").expect;
var BST = require("../BST");

describe("BinarySearchTrees", () => {
  var tree;
  beforeEach(() => {
    tree = new BST();
  });

  describe("loadFromArray", () => {
    beforeEach(() => {
      tree.loadFromArray([1, 2, 3, 4, 5]);
    });

    it("should load the array correctly for ascending order", () => {
      expect(tree.root.val).to.be.equal(3);
      expect(tree.root.left.val).to.be.equal(2);
      expect(tree.root.left.left.val).to.be.equal(1);
      expect(tree.root.right.val).to.be.equal(5);
      expect(tree.root.right.left.val).to.be.equal(4);
    });
  });

  describe("findMin", () => {
    var min;
    it("min to be the minimum value", () => {
      tree.loadFromArray([1, 2, 3, 4, 5]);
      min = tree.findMin();
      expect(min.val).to.be.equal(1);
    });
    it("min to be the minimum value", () => {
      tree.loadFromArray([6, 7, 8, 9]);
      min = tree.findMin();
      expect(min.val).to.be.equal(6);
    });
    it("min to be the minimum value", () => {
      tree.loadFromArray([5, 6]);
      min = tree.findMin();
      expect(min.val).to.be.equal(5);
    });
    it("min to be the minimum value", () => {
      tree.loadFromArray([6]);
      min = tree.findMin();
      expect(min.val).to.be.equal(6);
    });
  });
});
