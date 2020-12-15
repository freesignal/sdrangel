///////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2020 Edouard Griffiths, F4EXB                                   //
//                                                                               //
// This program is free software; you can redistribute it and/or modify          //
// it under the terms of the GNU General Public License as published by          //
// the Free Software Foundation as version 3 of the License, or                  //
// (at your option) any later version.                                           //
//                                                                               //
// This program is distributed in the hope that it will be useful,               //
// but WITHOUT ANY WARRANTY; without even the implied warranty of                //
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the                  //
// GNU General Public License V3 for more details.                               //
//                                                                               //
// You should have received a copy of the GNU General Public License             //
// along with this program. If not, see <http://www.gnu.org/licenses/>.          //
///////////////////////////////////////////////////////////////////////////////////

#include "feature/feature.h"
#include "util/messagequeue.h"
#include "maincore.h"
#include "messagepipescommon.h"
#include "messagepipesgcworker.h"

bool MessagePipesGCWorker::MessagePipesGC::existsProducer(const ChannelAPI *channel)
{
    return MainCore::instance()->existsChannel(channel);
}

bool MessagePipesGCWorker::MessagePipesGC::existsConsumer(const Feature *feature)
{
    return MainCore::instance()->existsFeature(feature);
}

void MessagePipesGCWorker::MessagePipesGC::sendMessageToConsumer(
    const MessageQueue *messageQueue,
    MessagePipesCommon::ChannelRegistrationKey channelKey,
    Feature *feature)
{
    MessagePipesCommon::MsgReportChannelDeleted *msg = MessagePipesCommon::MsgReportChannelDeleted::create(
        messageQueue, channelKey);
    feature->getInputMessageQueue()->push(msg);
}

MessagePipesGCWorker::MessagePipesGCWorker() :
    m_running(false)
{}

MessagePipesGCWorker::~MessagePipesGCWorker()
{}

void MessagePipesGCWorker::startWork()
{
    connect(&m_gcTimer, SIGNAL(timeout()), this, SLOT(processGC()));
    m_gcTimer.start(10000); // collect garbage every 10s
    m_running = true;
}

void MessagePipesGCWorker::stopWork()
{
    m_running = false;
    m_gcTimer.stop();
    disconnect(&m_gcTimer, SIGNAL(timeout()), this, SLOT(processGC()));
}

void MessagePipesGCWorker::processGC()
{
    // qDebug("MessagePipesGCWorker::processGC");
    m_messagePipesGC.processGC();
}
