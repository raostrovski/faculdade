<!DOCTYPE html>
<html>
<body>
<?php

    $host="127.0.0.1";
    $port=3306;
    $socket="";
    $user="root";
    $password="";
    $dbname="projectmedicenter";

    $con = new mysqli($host, $user, $password, $dbname, $port, $socket)
    	or die ('Could not connect to the database server' . mysqli_connect_error());

    $usuario = $_POST["txNome"];
	$senha   = $_POST["txSenha"];
	
	$sql       = "SELECT usuario, email, senha FROM usuario WHERE (usuario = '" . $usuario . "') OR (email = '" . $usuario . "')";
    $resultado = $con->query($sql);

	
    if($resultado->num_rows > 0){

        while($linhas = $resultado->fetch_assoc()){

			if($senha == $linhas["senha"]){
				
				echo "VERIFICOU CERTO";
				
			} else {
				
				echo "<script>alert('TA ERRADO PA CARAI');</script>";
			}
        }

    } else {

        echo "Deu certo nao";

    }

    $con->close();

?>
</body>
</html>