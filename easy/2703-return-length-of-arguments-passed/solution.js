/*
* =========================== *
*  Dominik Łempicki (kapitan) *
* =========================== *
*/

/**
 * @param {...(null|boolean|number|string|Array|Object)} args
 * @return {number}
 */
var argumentsLength = function(...args) {
    let ilosc = 0;
    for(const i of args) {
        ilosc += 1;
    }
    return ilosc;
};

/**
 * argumentsLength(1, 2, 3); // 3
 */