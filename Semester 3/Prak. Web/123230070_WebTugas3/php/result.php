<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Result</title>
    <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/css/bootstrap.min.css">
</head>

<?php
include "koneksi.php";
$id = $_GET["id"];
$query = "SELECT * FROM order_menu WHERE id_order = $id";
$hasil = mysqli_query($connect, $query);
$data = mysqli_fetch_assoc($hasil);

$menu = $data["menu"];
$size = $data["size"];
$hot = $data["temp_choice"];
$sweet = $data["sweetness_level"];
$note = $data["note"];

$hargaMenu = 0;
$hargaSweet = 0;
$hargaSize = $size == "Large" ? 5000 : 0;
$hargaDairy = 0;
$hargaTopping = 0;
$totalHarga = 0;

switch ($menu) {
    case 'Americano':
        $tax = 10;
        $hargaMenu = 12000;
        break;
    case 'Mochaccino':
        $tax = 10;
        $hargaMenu = 15000;
        break;
    case 'Hazelnut Latte':
        $tax = 15;
        $hargaMenu = 20000;
        break;
    case 'Vanilla Latte':
        $tax = 10;
        $hargaMenu = 17000;
        break;
    case 'Salted Caramel':
        $tax = 15;
        $hargaMenu = 18000;
        break;
    default:
        $tax = 0;
        $hargaMenu = 0;
        break;
}

?>

<body>
    <nav class="navbar navbar-expand-lg bg-body-tertiary sticky-top border-bottom">
        <div class="container-fluid">
            <a class="navbar-brand" href="#">Prak Web IF-D</a>
            <button class="navbar-toggler" type="button" data-bs-toggle="collapse" data-bs-target="#navbarNav" aria-controls="navbarNav" aria-expanded="false" aria-label="Toggle navigation">
                <span class="navbar-toggler-icon"></span>
            </button>
            <div class="collapse navbar-collapse" id="navbarNav">
                <ul class="navbar-nav ms-auto">
                    <li class="nav-item">
                        <a class="nav-link active" aria-current="page" href="../index.php">Dashboard</a>
                    </li>
                    <li class="nav-item">
                        <a class="nav-link" href="#">Logout</a>
                    </li>
                </ul>
            </div>
        </div>
    </nav>
    <div class="mx-3 mt-3">
        <table class="table table-striped">
            <thead>
                <tr>
                    <th colspan="2" class="text-center">Here's your order</th>
                </tr>
            </thead>
            <tbody>
                <tr>
                    <th scope="row">Menu</th>
                    <td><?= $menu ?></td>
                </tr>
                <tr>
                    <th scope="row">Size</th>
                    <td><?= $size ?></td>
                </tr>
                <tr>
                    <th scope="row">Hot/Ice</th>
                    <td><?= $hot ?></td>
                </tr>
                <tr>
                    <th scope="row">Sweetness Level</th>
                    <td><?= $sweet ?></td>
                </tr>
                <tr>
                    <th scope="row">Dairy</th>
                    <td>
                        <?php
                        $dairy = $data["dairy"];
                        echo $dairy;

                        switch ($dairy) {
                            case "Milk":
                                $hargaDairy = 5000;
                                break;
                            case "Oat Milk":
                                $hargaDairy = 6000;
                                break;
                            case "Almond Milk":
                                $hargaDairy = 7000;
                                break;
                            default:
                                $hargaDairy = 0;
                                break;
                        }
                        ?>
                    </td>
                </tr>
                <tr>
                    <th scope="row">Topping</th>
                    <td><?php
                        $topping = explode(", ",$data["topping"]);
                        $jumlahArr = count($topping);
                        foreach ($topping as $index => $item) {
                            echo $item;
                            if ($index < $jumlahArr - 1) {
                                echo ", ";
                            }

                            switch ($item) {
                                case "Caramel Sauce ":
                                    $hargaTopping += 3000;
                                    break;
                                case "Caramel Crumble":
                                    $hargaTopping += 3000;
                                    break;
                                case "Choco Granola":
                                    $hargaTopping += 4000;
                                    break;
                                case "Sea Salt Cream":
                                    $hargaTopping += 5000;
                                    break;
                                default:
                                    $hargaTopping += 0;
                                    break;
                            }
                        }

                        $hargaTax = (($hargaMenu + $hargaSize + $hargaDairy + $hargaTopping) * $tax / 100);
                        $totalHarga = $hargaMenu + $hargaSize + $hargaDairy + $hargaTopping + $hargaTax;
                        ?></td>
                </tr>
                <tr>
                    <th scope="row">Tax</th>
                    <td><?= "$tax%" ?></td>
                </tr>
                <tr>
                    <th scope="row">Note</th>
                    <td><?= $note ?></td>
                </tr>
                <tr>
                    <th scope="row">Total Price</th>
                    <td>
                        <div class="d-flex">
                            <div class="me-5">
                                <p class="mb-0">Default</p>
                                <p class="mb-0">Size</p>
                                <p class="mb-0">Dairy</p>
                                <p class="mb-0">Topping</p>
                                <p>Tax</p>
                                <p></p>
                            </div>
                            <div>
                                <p class="mb-0"><?= "Rp. $hargaMenu" ?></p>
                                <p class="mb-0"><?= "Rp. $hargaSize" ?></p>
                                <p class="mb-0"><?= "Rp. $hargaDairy" ?></p>
                                <p class="mb-0"><?= "Rp. $hargaTopping" ?></p>
                                <p class="mb-0"><?= "Rp. " . $hargaTax ?></p>
                                <p class="mb-0 fw-bold"><?= "Rp. $totalHarga" ?></p>
                            </div>
                        </div>
                    </td>
                </tr>
            </tbody>
        </table>
        <div class="d-flex justify-content-center">
            <a href="../index.php">
                <button class="btn btn-dark">Back to Dashboard!</button>
            </a>
        </div>
    </div>
</body>

</html>