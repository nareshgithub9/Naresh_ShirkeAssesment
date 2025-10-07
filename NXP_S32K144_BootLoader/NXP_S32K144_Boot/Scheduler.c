void schm_Cyclic(void) 
{
	if(schm_5ms) {
		Vtask_5ms();
		schm_5ms = 0;
	}
	if(schm_10ms) {
		Vtask_10ms();
		schm_10ms = 0;		
	}	
	if(schm_20ms) {
		Vtask_20ms();
		schm_20ms = 0;
	}	
	
	
}

void Vtask_5ms(void)
{
	CAN_Rx_Handler();
	UDS_req_handler();
}

void Vtask_10ms(void)
{
	Flash_Handler();
}