void Transclosure(unsigned char path[], int max) {
  int i, j, k;
  
  for(i = 0; i < max; i++)
    for(j = 0; j < max; j++)
      if(path[i*max+j])
	for(k = 0; k < max; k++)
	  if(path[j*max+k])
	    path[i*max+k] = 1;
}

void OOC_WarshallC_init0(void) { }

