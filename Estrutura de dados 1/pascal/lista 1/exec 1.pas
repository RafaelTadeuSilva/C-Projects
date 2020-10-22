Program Pzim ;
var mat : array [1..5, 1..5] of integer;
i, j, num, rodada : integer;
Begin
	i := 1;
	j := 1;
	num := 1;
	rodada := 1;
	while num <= 25 do
	begin
		//para a direita
		mat[i, j] := num;
		num := num + 1;
		j := j + 1;
		

		if(j = 6 - rodada) then
		begin
			//para baixo
			while i < 7 - rodada do
			begin 
				mat[i, j] := num;	
				num := num + 1;
				i := i+1;
			end;
			i := i-1;
			
			//para a esquerda
			while j > rodada do
			begin
				j := j-1;
				mat[i, j] := num;	
				num := num + 1;
			end;
			// para cima 
			while i > rodada + 1 do
			begin
				i := i-1;
				mat[i, j] := num;	
				num := num + 1;
				
			end;
		  rodada := rodada + 1;
			i := rodada; 
			j := rodada;
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