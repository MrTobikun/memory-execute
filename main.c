#include "meme_xec.h"

char* functionMemoryXor(char* buffer, long fileSize, char* key, long keyLength)
{
  for(int i = 0; i < fileSize; i++) {
    buffer[i] = buffer[i] ^ key[i%keyLength];
  }
  return buffer;
}

char* childrenFucntion(char* buffer, long fileSize, char* key, long keyLength)
{
  MEM_CREATE_FUNC_PTR;
  MEM_EXEC(childrenFucntion, functionMemoryXor, buffer, fileSize, key, keyLength);
  return MEM_EXEC_RETURN;
}

int main(int argc, char** argv)
{
  if (argc > 1) {
    FILE* input = fopen(argv[1], "rb");
    fseek(input, 0, SEEK_END);
    long fileSize = ftell(input);
    fseek(input, 0, SEEK_SET);

    // Read it into buffer
    char *buffer = malloc(fileSize + 1);
    fread(buffer, fileSize, 1, input);
    fclose(input);

    buffer[fileSize] = 0;

    char* key = argv[2];
    long keyLength = strlen(key);
    printf("memory result: %s\n", childrenFucntion(buffer, fileSize, key, keyLength));
  } else {
    printf("[NEWBIE-DETECT] no bro pls reading code\n");
  }

  return 0;
}
