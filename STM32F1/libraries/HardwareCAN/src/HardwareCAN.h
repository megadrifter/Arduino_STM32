/**
 * @brief HardwareCAN definitions
 */

#ifndef _HARDWARECAN_H_
#define _HARDWARECAN_H_

#include "utility/can.h"
#include "usb_serial.h"

/**
 * Defines the possible SPI communication speeds.
 */

class HardwareCAN
{
private:
public:
	CAN_Port* Port;
    HardwareCAN(CAN_Port *CANx_BASE);
    CAN_STATUS begin(void);

	uint32 MSR(void)
	{
		return Port->MSR;
	}

	uint32 RF0R(void)
	{
		return Port->RF0R;
	}

	void set_pool_mode(void);
	void set_irq_mode(void);

    CAN_STATUS begin(CAN_SPEED speed, uint32 mode);
	void end(void);

	CAN_STATUS filter(uint8 idx, uint32 id, uint32 mask, int ext_id = 0);
	CAN_STATUS map(CAN_GPIO_MAP remap);
	CAN_STATUS status(void);

	CAN_TX_MBX send(CanMsg* message);
	void cancel(CAN_TX_MBX mbx);

	uint8 available(void);
	uint8 frame_lost(void);

	CanMsg* recv(void);

	void free(void);
	void clear(void);

	uint8 fifo_ready(CAN_FIFO fifo);
	CanMsg* read(CAN_FIFO fifo, CanMsg* msg);
	void release(CAN_FIFO fifo);
};

#endif
