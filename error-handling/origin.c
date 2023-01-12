int parseFile1(char* file_name)
{
  int return_value = ERROR;
  FILE* file_pointer = 0;
  char* buffer = 0;

  if(file_name!=NULL)
  {
    if(file_pointer=fopen(file_name, "r"))
    {
      if(buffer=malloc(BUFFER_SIZE))
      {
        /* parse file content*/
        return_value = NO_KEYWORD_FOUND;
        while(fgets(buffer, BUFFER_SIZE, file_pointer)!=NULL)
        {
          if(strcmp("KEYWORD_ONE\n", buffer)==0)
          {
            return_value = KEYWORD_ONE_FOUND_FIRST;
            break;
          }
          if(strcmp("KEYWORD_TWO\n", buffer)==0)
          {
            return_value = KEYWORD_TWO_FOUND_FIRST;
            break;
          }
        }
        free(buffer);
      }
      fclose(file_pointer);
    }
  }
  return return_value;
}

int parseFile2(char* file_name)
{
  int return_value = ERROR;
  FILE* file_pointer = 0;
  char* buffer = 0;

  assert(file_name!=NULL && "Invalid filename");
  if(file_pointer=fopen(file_name, "r"))
  {
    if(buffer=malloc(BUFFER_SIZE))
    {
      return_value = searchFileForKeywords(buffer, file_pointer);
      free(buffer);
    }
    fclose(file_pointer);
  }
  return return_value;
}

int parseFile3(char* file_name)
{
  int return_value = ERROR;
  FILE* file_pointer = 0;
  char* buffer = 0;

  assert(file_name!=NULL && "Invalid filename");
  if(!(file_pointer=fopen(file_name, "r")))
  {
    goto error_fileopen;
  }
  if(!(buffer=malloc(BUFFER_SIZE)))
  {
    goto error_malloc;
  }
  return_value = searchFileForKeywords(buffer, file_pointer);
  free(buffer);
error_malloc:
  fclose(file_pointer);
error_fileopen:
  return return_value;
}

int parseFile4(char* file_name)
{
  int return_value = ERROR;
  FILE* file_pointer = 0;
  char* buffer = 0;

  assert(file_name!=NULL && "Invalid filename");
  if((file_pointer=fopen(file_name, "r")) &&
     (buffer=malloc(BUFFER_SIZE)))
  {
    return_value = searchFileForKeywords(buffer, file_pointer);
  }
  if(file_pointer)
  {
    fclose(file_pointer);
  }
  if(buffer)
  {
    free(buffer);
  }
  return return_value;
}
