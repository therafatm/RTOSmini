void sender()
{
  unsigned int send_msg = 9;
  unsigned int v = send_msg;
  PID pid = 3;
  printf("sender sending to task(pid:%u): ----> %u\n", pid, v);
  Msg_Send(3, GET, &v);
  printf("sender received reply: <---- %u\n", v);
  Task_Next();
}

void receiver()
{
  unsigned int v = 0;
  unsigned int reply_msg = 4;
  PID reply_pid = Msg_Recv(ALL, &v);
  printf("receiver recieved from sender(pid:%u): <---- %u\n", reply_pid, v);
  printf("starting replying to sender(pid:%u): ----> %u\n", reply_pid, reply_msg);
  Msg_Rply(reply_pid, reply_msg);
}

void a_main() {
  Task_Create_System(sender, 0);
  Task_Create_RR(receiver, 0);
}