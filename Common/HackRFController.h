/*
 *   Copyright (C) 2013 by Jonathan Naylor G4KLX
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; either version 2 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program; if not, write to the Free Software
 *   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#ifndef	HackRFController_H
#define	HackRFController_H

#include <wx/wx.h>

#include "SDRController.h"
#include "Frequency.h"
#include "ControlInterface.h"

#if defined(_WIN32)
#include "libusb.h"
#else
#include <libusb-1.0/libusb.h>
#endif

class CHackRFController : public ISDRController {
public:
	CHackRFController();
	virtual ~CHackRFController();

	virtual void setCallback(IControlInterface* callback);

	virtual bool open();
	virtual void enableTX(bool on);
	virtual void enableRX(bool on);
	virtual void setTXAndFreq(bool transmit, const CFrequency& freq);
	virtual void close();

private:
	libusb_context*       m_context;
	libusb_device_handle* m_device;
	IControlInterface*    m_callback;
	CFrequency            m_frequency;
	bool                  m_txEnable;
	bool                  m_tx;

	bool setFrequency(const CFrequency& freq);
	bool setTransmit(bool tx);
};

#endif
