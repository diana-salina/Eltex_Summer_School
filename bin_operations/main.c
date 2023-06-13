#include <stdio.h>

void print_bytes(int a) {
  const int byte_size = 8;
  const int byte_number = 4;
  const unsigned char mask = 0xFF;
  for (int i = 0; i < byte_number; ++i) {
    const unsigned char byte = (a >> (byte_size * i)) & mask;
    printf("%d byte: %x\n", i + 1, byte);
  }
}

void change_byte(int* a, int n, unsigned char byte) {
  const int byte_size = 8;
  const int move = byte_size * (n - 1);
  *a &= ~(1 << move);
  *a |= byte << move;
}

int main() {
  int a = 0xDDCCBBAA;

  printf("a bytes:\n");
  print_bytes(a);
  change_byte(&a, 3, 0xEE);
  printf("new a bytes:\n");
  print_bytes(a);
  return 0;
}
