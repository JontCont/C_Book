實習21：監控AD/DA模組
【實習目的】
在這個實習中，我們要在Linux PC中撰寫I-7012 / I-7021的通訊程式。

【動作要求】
程式在執行後，會作3件事：
(1) 讀取I-7012類比輸入值，將其顯示出來。
(2) 設定I-7021類比輸出值，將其設為10V。
(3) 5秒後，將從I-7012讀取到的類比輸入值，設為I-7012的類比輸出值。

【程式】
/* ex7012.c */
#include "i7k.h"
#define RCVBUF_SIZE	16

int main()
{
int		fd,i;
char 	*cmd, cmd2[100];
char 	rbuf[RCVBUF_SIZE], rbuf1[RCVBUF_SIZE];
__tod_t	texp;
int		r;
double	dout;

/* 開啟串列埠 */
fd = sio_open("/dev/ttyS0", B9600, DATA_BITS_8, NO_PARITY, 
		ONE_STOP_BIT);
if (fd == ERR_PORT_OPEN) {
		printf("open port failed!\n");
		return (-1);
}

/* 設為非正規模式 */
sio_set_noncan(fd);

/* 設定讀取的timeout時間為10秒 */
sio_set_timer(fd,0,10);

/* 讀取7012的類比輸入 */
cmd="#02\r";
r=i7k_send_readt(fd,cmd,rbuf,RCVBUF_SIZE,&texp);
rbuf[r]=0;

/* 將讀到的電壓值顯示出來 */
printf("read : %s\n",rbuf);

/* 設定7021的類比輸出值為10V */
cmd="#0310.000\r";
r=i7k_send_readt(fd,cmd,rbuf,RCVBUF_SIZE,&texp);
rbuf[r]=0;
printf("send: %s\n",rbuf);

sleep(5);

/* 將從7012讀到的電壓值傳給rbuf1陣列 */
for (i=0;i<6;i++) {
　　rbuf1[i]=rbuf[i+3];
}
rbuf1[6]='\r';

/* 組成設定7021類比輸出的命令 */
strcpy(cmd2,"#030");
strcat(cmd2, rbuf1);

r=i7k_send_readt(fd,cmd2,rbuf,RCVBUF_SIZE,&texp);

sio_close(fd);
return (0);
}  /* main */


