Program Pzim ;
var mat : array[1..5, 1..5] of integer;
i, j, num, maxI, maxJ, minI, minJ  :integer;
volta : boolean;
Begin
	i := 1;
	j := 1;
	maxI := 5;
	maxJ := 5;
	minI := 2;
	minJ := 1;	
	num := 1;
	
	volta := false;
	for num:=1 to 25 do
	begin
		mat[i,j] := num;
		if(volta = false) then
		begin
			if(j < maxJ) then
        j:= j + 1
			else if(i < maxI) then
	       i:= i + 1;
	  	if(i = maxI) and (j= maxJ) then
	  	begin
				volta := true;
				maxI := maxI -1;
				maxJ := maxJ -1;
			end;
	  end	
		else
		begin
			 if(j > minJ) then
	        j:= j - 1
				else if(i > minI) then
		       i:= i - 1;
		  	if(i = minI) and (j = minJ) then
				begin
		  		volta := false;
					minI := minI +1;
					minJ := minJ +1;
		  	end;
		end;  
	end;
	
	for i:=1 to 5 do
	begin
		for j:= 1 to 5 do
		begin
			write(mat[i,j], '	');
		end;
		writeln;
	end;	
End.