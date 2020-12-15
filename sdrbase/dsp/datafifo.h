///////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2020 F4EXB                                                      //
// written by Edouard Griffiths                                                  //
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

#ifndef INCLUDE_DATAFIFO_H
#define INCLUDE_DATAFIFO_H

#include <QObject>
#include <QMutex>
#include <QElapsedTimer>
#include <QByteArray>

#include "dsp/dsptypes.h"
#include "export.h"

class SDRBASE_API DataFifo : public QObject {
	Q_OBJECT

private:
	QMutex m_mutex;
	QElapsedTimer m_msgRateTimer;
	int m_suppressed;

	QByteArray m_data;

	unsigned int m_size;
	unsigned int m_fill;
	unsigned int m_head;
	unsigned int m_tail;

	void create(unsigned int s);

public:
	DataFifo(QObject* parent = nullptr);
	DataFifo(int size, QObject* parent = nullptr);
    DataFifo(const DataFifo& other);
	~DataFifo();

	bool setSize(int size);
    void reset();
	inline unsigned int size() const { return m_size; }
	inline unsigned int fill() { QMutexLocker mutexLocker(&m_mutex); unsigned int fill = m_fill; return fill; }

	unsigned int write(const quint8* data, unsigned int count);
	unsigned int write(QByteArray::const_iterator begin, QByteArray::const_iterator end);

	unsigned int read(QByteArray::iterator begin, QByteArray::iterator end);

	unsigned int readBegin(unsigned int count,
		QByteArray::iterator* part1Begin, QByteArray::iterator* part1End,
		QByteArray::iterator* part2Begin, QByteArray::iterator* part2End);
	unsigned int readCommit(unsigned int count);
    static unsigned int getSizePolicy(unsigned int sampleRate);

signals:
	void dataReady();
};

#endif // INCLUDE_DATAFIFO_H
