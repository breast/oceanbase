/*
 * (C) 2007-2010 Taobao Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * Shadow server
 *
 * Version: $Id$
 *
 * Authors:
 *   ruohai <ruohai@taobao.com>
 *
 */
#ifndef OCEANBASE_COMMON_SHADOW_SERVER_H_
#define OCEANBASE_COMMON_SHADOW_SERVER_H_

#include "ob_packet.h"
#include "ob_base_server.h"

namespace oceanbase
{
  namespace common
  {
    class ObShadowServer : public ObBaseServer
    {
      public:
        explicit ObShadowServer(ObBaseServer* master);
        virtual ~ObShadowServer();

        void set_priority(const int32_t priority);
    
        virtual tbnet::IPacketHandler::HPRetCode handlePacket(tbnet::Connection *connection, tbnet::Packet *packet);

        virtual bool handleBatchPacket(tbnet::Connection *connection, tbnet::PacketQueue &packetQueue);

      private:
        int32_t priority_;
        ObBaseServer* master_;
    };
  } /* common */
} /* oceanbase */

#endif /* end of include guard: OCEANBASE_COMMON_SHADOW_SERVER_H_ */
