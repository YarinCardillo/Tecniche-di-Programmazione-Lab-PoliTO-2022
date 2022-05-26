/*	fscanf(fin, "%c", &charBack);

	while(fscanf(fin, "%c", &charFront) != EOF){

		if(charBack == charFront){
			count++;
		}
		else{

			fprintf(fout, "%c", charBack);
			printf("%c", charBack);
			fflush(stdout);
    		//fprintf(fout, "$%d", count);
			if (count > 1)
			{
				fprintf(fout, "$%d", count);
				printf("$%d", count);
				fflush(stdout);
			}
			count = 0;
		}

		charBack = charFront;

	}
	fprintf(fout, "%c", charBack);
	printf("%c", charBack);
	fflush(stdout);
 */