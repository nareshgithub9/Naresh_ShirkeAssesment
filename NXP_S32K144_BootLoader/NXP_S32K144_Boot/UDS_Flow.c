

void UDS_req_handler(void)
{
	CAN_Rx_data_parser();
	
}

void UDS_Session_handler(void)
{
	
}

void SendNRC(uint8_t NRC_num) 
{
	update_UDS_Paylod(NRC_num);
	CAN_Send(UDS_ID,uds_payload);
}

void CAN_TP_handler(void)
{

}