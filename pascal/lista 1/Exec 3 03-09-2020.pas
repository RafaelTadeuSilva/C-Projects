DProgram Pzim ;
var mat : array [1..5, 1..5] of integer;
i, j, num, diag : integer;
Begin
	i := 1;
	j := 1;
	num := 1;
	diag := 1;
	while num <= 15 do
	begin
		if diag = 1 then
			mat[i, j] := num
		else
		begin
		  mat[i, j] := num;
		  mat[j, i] := num;
		end;
		
		num := num + 1;
		j := j + 1;
		i := i + 1;
		if(j = 6) then
		begin
			diag := diag + 1;
			i:= 1;
			j:= diag;
		end;
	end;
			 
	for i := 1 to 5 do
	begin
		for j := 1 to 5 do
		begin
			write(mat[i,j], '	');
		end;
		writeln;
	end;	
	readkey;
End.