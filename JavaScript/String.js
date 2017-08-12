var ReverseCString = function (str) {
    var end = str.length - 1,
        result = '';

    for (; end >= 0; --end) {
        result += str[end]
    }
    return result;
}

var RemoveDups = function (str) {
    var result = "",
        lookup = {};

    for (var i = 0; i < str.length; i++) {
        if (!lookup[str[i]]) {
            result += str[i];
            lookup[str[i]] = 1;
        }
    }

    return result;
}

var isAnagram = function (str1, str2) {

    if (str1.length != str2.length) return false;

    var count = {},
        str1Total = 0,
        str2Total = 0,
        length = 0;

    for (var i = 0; i < str1.length; i++) {
        if (!count[str1[i]]) {
            count[str1[i]] = ++length;
        }
        str1Total += count[str1[i]];

        if (!count[str2[i]]) {
            count[str2[i]] = ++length;
        }
        str2Total += count[str2[i]];
    }

    return str1Total === str2Total;
}


module.exports = {
    ReverseCString,
    RemoveDups,
    isAnagram
}