#include "UnixWrappers.hpp"
#include "NetworkWrappers.hpp"
#include "ErrorHandler.hpp"

#include <memory>
#include <cstring>
#include <iostream>

#pragma once

//constants
const int MAXLINE = 4096;
const int SERV_PORT = 9878;

//global variables
extern ErrorHandler g_errorHandler;
extern NetworkWrappers g_networkWrapper;
extern UnixWrappers g_unixWrapper;

extern int g_sockfd;
extern struct sockaddr_in g_servaddr;
extern ssize_t g_receivedBytes;
extern Message g_receivedMessage;

//declaration of functions
void Fputs(const char *ptr, FILE *stream);
char* Fgets(char *ptr, int n, FILE *stream);

void initializeConnection(char** p_argv);
void receiveMessageFromServer(const int p_msgId);
void receiveMessageClientSendFileIndFromServer(std::ofstream& p_outFile, long long& p_sumOfReceivedBytes);

//testcases
void connectToServerTest(char** p_argv);
void exchangeAFewSimpleMessagesWithServerTest(char** p_argv);
void sendFileTransferRequestAndReceiveRequestedFileTest(char** p_argv);
