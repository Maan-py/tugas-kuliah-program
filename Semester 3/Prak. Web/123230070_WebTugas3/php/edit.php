<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Tugas 1</title>
    <link rel="stylesheet" href="../css/style.css">
    <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/css/bootstrap.min.css">
</head>

<?php
include "koneksi.php";
$id = $_GET["id"];
$query = "SELECT * FROM order_menu WHERE id_order = $id";
$hasil = mysqli_query($connect, $query);
$data = mysqli_fetch_assoc($hasil);

$toppings = explode(", ", $data["topping"]);


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
    <div class="container">
        <h3 class="text-center">Edit Your Order</h3>
        <form action="" method="post" class="p-3 m-3 border border-dark border-2 rounded">
            <div class="mb-3">
                <label for="menu" class="form-label fw-bold">Menu</label>
                <select name="menu" id="menu" class="form-select" require>
                    <option value="">Menu</option>
                    <option value="Americano" <?php $data["menu"] == "Americano" ? print("selected") : print("") ?>>Americano</option>
                    <option value="Mochaccino" <?php $data["menu"] == "Mochaccino" ? print("selected") : print("") ?>>Mochaccino</option>
                    <option value="Hazelnut Latte" <?php $data["menu"] == "Hazelnut Latte" ? print("selected") : print("") ?>>Hazelnut Latte</option>
                    <option value="Vanilla Latte" <?php $data["menu"] == "Vanilla Latte" ? print("selected") : print("") ?>>Vanilla Latte</option>
                    <option value="Salted Caramel" <?php $data["menu"] == "Salted Caramel" ? print("selected") : print("") ?>>Salted Caramel</option>
                </select>
            </div>
            <div class="mb-3">
                <label for="" class="form-label fw-bold">Hot/Ice</label>
                <div class="d-flex">
                    <div>
                        <input class="form-check-input" type="radio" value="Hot" id="hot" name="hot" <?php $data["temp_choice"] == "Hot" ? print("checked") : print("") ?>>
                        <label class="form-check-label mx-2" for="hot">
                            Hot
                        </label>
                    </div>
                    <div>
                        <input class="form-check-input" type="radio" name="hot" value="Ice" id="ice" <?php $data["temp_choice"] == "Ice" ? print("checked") : print("") ?>>
                        <label class="form-check-label" for="ice">
                            Ice
                        </label>
                    </div>
                </div>
            </div>
            <div class="mb-3">
                <label for="" class="form-label fw-bold">Size</label>
                <div class="d-flex">
                    <div class="mx-2">
                        <input class="form-check-input" type="radio" value="Regular" id="regular" name="size" <?php $data["size"] == "Regular" ? print("checked") : print("") ?>>
                        <label class="form-check-label" for="regular">
                            Regular
                        </label>
                    </div>
                    <div>
                        <input class="form-check-input" type="radio" value="Large" name="size" value="Large" id="large" <?php $data["size"] == "Large" ? print("checked") : print("") ?>>
                        <label class="form-check-label" for="large">
                            Large
                        </label>
                    </div>
                </div>
            </div>
            <div class="mb-3">
                <label for="" class="form-label fw-bold">Sweetness Level</label>
                <div class="d-flex">
                    <div class="mx-2">
                        <input class="form-check-input" type="radio" id="normal" value="Normal" name="sweet" <?php $data["sweetness_level"] == "Normal" ? print("checked") : print("") ?>>
                        <label class="form-check-label" for="normal">
                            Normal Sweet
                        </label>
                    </div>
                    <div>
                        <input class="form-check-input" type="radio" name="sweet" value="Less" id="less" <?php $data["sweetness_level"] == "Less" ? print("checked") : print("") ?>>
                        <label class="form-check-label" for="less">
                            Less Sweet
                        </label>
                    </div>
                </div>
            </div>
            <div class="mb-3">
                <div>
                    <label for="" class="form-label fw-bold">Dairy</label>
                    <label for="" class="extra-small text-secondary">optional</label>
                </div>
                <div class="d-flex">
                    <div class="mx-2">
                        <input class="form-check-input" type="radio" id="milk" value="Milk" name="dairy" <?php $data["dairy"] == "Milk" ? print("checked") : print("") ?>>
                        <label class="form-check-label" for="milk">
                            Milk
                        </label>
                    </div>
                    <div class="mx-2">
                        <input class="form-check-input" type="radio" name="dairy" value="Oat Milk" id="oatMilk" <?php $data["dairy"] == "Oat Milk" ? print("checked") : print("") ?>>
                        <label class="form-check-label" for="oatMilk">
                            Oat Milk
                        </label>
                    </div>
                    <div>
                        <input class="form-check-input" type="radio" name="dairy" value="Almond Milk" id="almondMilk" <?php $data["dairy"] == "Almond Milk" ? print("checked") : print("") ?>>
                        <label class="form-check-label" for="almondMilk">
                            Almond Milk
                        </label>
                    </div>
                </div>
            </div>
            <div class="mb-3">
                <div>
                    <label for="" class="form-label fw-bold">Topping</label>
                    <label for="" class="extra-small text-secondary">optional</label>
                </div>
                <div class="d-flex flex-column">
                    <div class="mx-2">
                        <input class="form-check-input" type="checkbox" id="caramelSauce" value="Caramel Sauce"
                            name="topping[]" <?php foreach ($toppings as $key => $topping) {
                                                    $topping == "Caramel Sauce" ? print("checked") : print("");
                                                } ?>>
                        <label class="form-check-label" for="caramelSauce">
                            Caramel Sauce
                        </label>
                    </div>
                    <div class="mx-2">
                        <input class="form-check-input" type="checkbox" name="topping[]" value="Caramel Crumble"
                            id="caramelCrumble" <?php foreach ($toppings as $key => $topping) {
                                                    $topping == "Caramel Crumble" ? print("checked") : print("");
                                                } ?>>
                        <label class="form-check-label" for="caramelCrumble">
                            Caramel Crumble
                        </label>
                    </div>
                    <div class="mx-2">
                        <input class="form-check-input" type="checkbox" name="topping[]" value="Choco Granola"
                            id="chocoGranola" <?php foreach ($toppings as $key => $topping) {
                                                    $topping == "Choco Granola" ? print("checked") : print("");
                                                } ?>>
                        <label class="form-check-label" for="chocoGranola">
                            Choco Granola
                        </label>
                    </div>
                    <div class="mx-2">
                        <input class="form-check-input" type="checkbox" name="topping[]" value="Sea Salt Cream"
                            id="seaSaltCream" <?php foreach ($toppings as $key => $topping) {
                                                    $topping == "Sea Salt Cream" ? print("checked") : print("");
                                                } ?>>
                        <label class="form-check-label" for="seaSaltCream">
                            Sea Salt Cream
                        </label>
                    </div>
                </div>
            </div>
            <div class="mb-3">
                <label for="" class="form-label fw-bold">Note</label>
                <textarea class="form-control" placeholder="Write your additional note here" id="floatingTextarea"
                    name="note"><?= $data["note"] ?></textarea>
            </div>
            <div class="mb-3">
                <button type="submit" class="btn btn-primary">Edit</button>
                <button type="reset" class="btn btn-danger">Reset</button>
            </div>
        </form>
    </div>
</body>

</html>