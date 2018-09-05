<?php
session_start();
include "bd.php";

$usuario = (isset($_POST["txNome"])) ? $_POST["txNome"] : '';
$senha   = (isset($_POST["txSenha"])) ? $_POST["txSenha"] : '';

if(empty($usuario)){

    $retorno = ['codigo' => 0, 'mensagem' => 'Preencha seu usuario!'];
    echo json_encode($retorno);
    exit();

}
if(empty($senha)){

    $retorno = ['codigo' => 0, 'mensagem' => 'Preencha a sua senha!'];
    echo json_encode($retorno);
    exit();
}

//Valida se $usuario é um email
if(preg_match('/.*@{1}.*', $usuario) == 1){
    if (!filter_var($email, FILTER_VALIDATE_EMAIL)):
        $retorno = ['codigo' => 0, 'mensagem' => 'Formato de e-mail inválido!'];
        echo json_encode($retorno);
        exit();
    endif;
}

//valida as informações com o banco


$sql       = "SELECT usuario, email, senha FROM usuario WHERE (usuario = '" . $usuario . "') OR (email = '" . $usuario . "') LIMIT 1";
$resultado = $con->query($sql);
$resultado = $resultado->fetch_assoc();

if(!empty($resultado) && ($senha == $resultado['senha'])){
    $_SESSION['id'] = $resultado['usuario'];
	$_SESSION['email'] = $resultado['email'];
	$_SESSION['logado'] = 'SIM';
} else {
	$_SESSION['logado'] = 'NAO';
}

if($_SESSION['logado'] == 'SIM'){
    $retorno = array('codigo' => 1, 'mensagem' => 'Logado com sucesso!');
	echo json_encode($retorno);
	exit();
} else {
    $retorno = array('codigo' => 0, 'mensagem' => 'Usuario ou senha incorretas!');
	echo json_encode($retorno);
	exit();
}

?>