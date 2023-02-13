//
// Created by Sokhibjon Orzikulov on 13/02/23.
//

#ifndef NEKO_HTTP_H
#define NEKO_HTTP_H

#include <stdio.h>
#include <string.h>

//   ______
//  /_  __/_  ______  ___  _____
//   / / / / / / __ \/ _ \/ ___/
//  / / / /_/ / /_/ /  __(__  )
// /_/  \__, / .___/\___/____/
//     /____/_/

extern char *method, // "GET" or "POST"
        *uri,        // "/index.html" things before '?'
        *qs,         // "a=1&b=2"   things after '?'
        *prot,       // "HTTP/1.1"
        *payload;    // for POST

extern int payload_size;

//    _____                              ___________
//   / ___/___  ______   _____  _____   / ____/ ___/
//   \__ \/ _ \/ ___/ | / / _ \/ ___/  / /_   \__ \
//  ___/ /  __/ /   | |/ /  __/ /     / __/  ___/ /
// /____/\___/_/    |___/\___/_/     /_/    /____/

void serve_forever(const char *PORT);
char *request_header(const char *name);

typedef struct {
    char *name;
    char *value;
} header_t;

static header_t reqhdr[17] = {{ "\0", "\0" }};
header_t *request_headers(void);

//     ____                __
//    /  _/___ ___  ____  / /____
//    / // __ `__ \/ __ \/ / ___/
//  _/ // / / / / / /_/ / (__  )
// /___/_/ /_/ /_/ .___/_/____/
//              /_/

void route();

// Response
#define RESPONSE_PROTOCOL "HTTP/1.1"

#define HTTP_200 printf("%s 200 OK\n\n", RESPONSE_PROTOCOL)
#define HTTP_201 printf("%s 201 Created\n\n", RESPONSE_PROTOCOL)
#define HTTP_404 printf("%s 404 Not found\n\n", RESPONSE_PROTOCOL)
#define HTTP_500 printf("%s 500 Internal Server Error\n\n", RESPONSE_PROTOCOL)

#endif //NEKO_HTTP_H
