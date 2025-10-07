/***********************************************************************************************
*
* @brief    main() - Program entry function
* @param    none
* @return   none
*
************************************************************************************************/
int main(void)
{
	uint8_t UpdateRequestFlag  = NULL;
	Init_Sys();

	Init_DFlash();
	
	DFLASH_Read(UPDATE_REQ_ADDR,&UpdateRequestFlag);
	
	switch(UpdateRequestFlag) 
	{
		case 1://Normal_Execution:No_update
		       Check_integrity(APP_ADDR);
			   JumpToApplication();
			   break;
		
		case 2://Application_update 
			   Check_integrity(SLOTB_ADDR);
		       CopyApplication(SLOTB_ADDR,APP_ADDR);
			   UpdateRequestFlag = 0x01
			   DFLASH_Write(UPDATE_REQ_ADDR,&UpdateRequestFlag);
			   break;
		case 3://UDS_update 
			   CAN_init();
		       Flash_driver_init();
			   Timer_Init();
			   UDS_Comm_init();
			   DFLASH_Write(UPDATE_REQ_ADDR,&UpdateRequestFlag);
			   
			   whille(1) 
			   {
				   
				schm_Cyclic();   
			   
			   }
			   break;	
		case default://Application_update 
			   UpdateRequestFlag = 0x03;
			   DFLASH_Write(UPDATE_REQ_ADDR,&UpdateRequestFlag);
			   MCU_reset();
			   break;			   
	}
	
	
}

