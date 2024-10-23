<?php
include "koneksi.php";

$menu = $_POST["menu"];
$temp = $_POST["hot"];
$size = $_POST["size"];
$sweet = $_POST["sweet"];
$note = $_POST["note"] == "" ? "None" : $_POST["note"];
$topping = isset($_POST["topping"]) ? implode(", ", $_POST["topping"]) : "None";
$dairy = isset($_POST["dairy"]) ? $_POST["dairy"] : "None";

$query = "INSERT INTO order_menu (id_order, menu, temp_choice, size, sweetness_level, dairy, topping, note) VALUES (NULL, '$menu', '$temp', '$size', '$sweet', '$dairy', '$topping', '$note')";

$hasil = mysqli_query($connect, $query);

if ($hasil) {
    header("location: ../index.php");
} else {
    header("location: ../input.php?status=gagal");
}
