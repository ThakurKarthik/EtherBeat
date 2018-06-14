#include "parser.h"
#include "block_store.h"
#include <sqlite3.h>
#include <iostream>
#include <stdio.h>

int main() {
    std::cout << "Hello, World!" << std::endl;

    sqlite3 *db;
    int rc = sqlite3_open("ethereum_blockchain.db", &db);

    if( rc ) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return(0);
    } else {
        fprintf(stderr, "Opened database successfully\n");
    }
    // create database
    createRDBMSSchema(db);


    Parser p("/home/prabushitha/.ethereum/rinkeby/geth/chaindata");

    Block b = p.getBlock(55);
    // b.print();

    storeBlockInRDBMS(db, b);

    sqlite3_close(db);
    return 0;
}