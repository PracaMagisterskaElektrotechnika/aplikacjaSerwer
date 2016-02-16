#include "CommonTypes.h"

class IUnixWrappers
{
public:

    virtual void send(int p_socketDescriptor,
                      const void* p_messageToSent,
                      size_t p_messageLenghtInBytes,
                      int p_transmissionType = 0) const = 0;

    virtual ssize_t recv(int p_socketDescriptor,
                         void* p_receivedMessage,
                         size_t p_messageLenghtInBytes,
                         int p_transmissionType = MSG_WAITALL) const = 0;

    virtual void close(int p_socketDescriptor) const = 0;
    virtual pid_t fork(void) const = 0;

};
