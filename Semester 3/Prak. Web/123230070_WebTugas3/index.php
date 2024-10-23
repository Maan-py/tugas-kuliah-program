<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Tampilan Order</title>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-QWTKZyjpPEjISv5WaRU9OFeRpok6YctnYmDr5pNlyT2bRjXh0JMhjY6hW+ALEwIH" crossorigin="anonymous">
    <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.11.3/font/bootstrap-icons.min.css">
</head>

<?php
include "php/koneksi.php";

$query = "SELECT * FROM order_menu";
$hasil = mysqli_query($connect, $query);
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
                        <a class="nav-link active" aria-current="page" href="index.php">Dashboard</a>
                    </li>
                    <li class="nav-item">
                        <a class="nav-link" href="#">Logout</a>
                    </li>
                </ul>
            </div>
        </div>
    </nav>
    <main class="mx-2">
        <div class="d-flex mt-5 container">
            <h5>All Orders</h5>
            <a href="php/input.php" class=" ms-auto">
                <button class="btn btn-primary">Add Order</button>
            </a>
        </div>
        <div class="container mt-4">
            <table class="table table-bordered">
                <thead>
                    <tr>
                        <th scope="col">No</th>
                        <th scope="col">Menu</th>
                        <th scope="col">Hot/Ice</th>
                        <th scope="col">Size</th>
                        <th scope="col" width="15%">Sweetness Level</th>
                        <th scope="col">Dairy</th>
                        <th scope="col">Topping</th>
                        <th scope="col">Note</th>
                        <th scope="col" width="15%">Action</th>
                    </tr>
                </thead>
                <tbody>

                    <?php

                    while ($data = mysqli_fetch_assoc($hasil)) {
                    ?><tr>
                            <th scope="row"><?= $data["id_order"] ?></th>
                            <td><?= $data["menu"] ?></td>
                            <td><?= $data["temp_choice"] ?></td>
                            <td><?= $data["size"] ?></td>
                            <td><?= $data["sweetness_level"] ?></td>
                            <td><?= $data["dairy"] ?></td>
                            <td><?= $data["topping"] ?></td>
                            <td><?= $data["note"] ?></td>
                            <td>
                                <div>
                                    <a href="php/result.php?id=<?= $data["id_order"] ?>" class="text-decoration-none">
                                        <button class="btn btn-primary">
                                            <i class="bi bi-eye"></i>
                                        </button>
                                    </a>
                                    <a href="php/edit.php?id=<?= $data["id_order"] ?>" class="text-decoration-none"">
                                        <button class=" btn btn-primary">
                                        <i class="bi bi-pencil"></i>
                                        </button>
                                    </a>
                                    <a href="php/hapus.php?id=<?= $data["id_order"] ?>" class="text-decoration-none"">
                                        <button class=" btn btn-danger">
                                        <i class="bi bi-trash"></i>
                                        </button>
                                    </a>
                                </div>
                            </td>
                        </tr>
                    <?php
                    }
                    ?>
                </tbody>
            </table>
        </div>
    </main>
</body>

</html>