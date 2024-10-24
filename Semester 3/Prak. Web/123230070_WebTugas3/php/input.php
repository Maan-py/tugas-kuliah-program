<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Tugas 1</title>
    <link rel="stylesheet" href="style.css">
    <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/css/bootstrap.min.css">
</head>

<?php
if (isset($_GET["status"])) {
    switch ($_GET["status"]) {
        case 'gagal':
            echo "Gagal Input";
            break;
    }
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
    <div class="container">
        <h3 class="text-center">Input Your Order</h3>
        <form action="tambah.php" method="post" class="p-3 m-3 border border-dark border-2 rounded">
            <div class="mb-3">
                <label for="menu" class="form-label fw-bold">Menu</label>
                <select name="menu" id="menu" class="form-select" required>
                    <option value="">Menu</option>
                    <option value="Americano">Americano</option>
                    <option value="Mochaccino">Mochaccino</option>
                    <option value="Hazelnut Latte">Hazelnut Latte</option>
                    <option value="Vanilla Latte">Vanilla Latte</option>
                    <option value="Salted Caramel">Salted Caramel</option>
                </select>
            </div>
            <div class="mb-3">
                <label for="" class="form-label fw-bold">Hot/Ice</label>
                <div class="d-flex">
                    <div>
                        <input class="form-check-input" type="radio" value="Hot" id="hot" name="hot">
                        <label class="form-check-label mx-2" for="hot">
                            Hot
                        </label>
                    </div>
                    <div>
                        <input class="form-check-input" type="radio" name="hot" value="Ice" id="ice" checked>
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
                        <input class="form-check-input" type="radio" value="Regular" id="regular" name="size" checked>
                        <label class="form-check-label" for="regular">
                            Regular
                        </label>
                    </div>
                    <div>
                        <input class="form-check-input" type="radio" value="Large" name="size" value="Large" id="large">
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
                        <input class="form-check-input" type="radio" id="normal" value="Normal" name="sweet" checked>
                        <label class="form-check-label" for="normal">
                            Normal Sweet
                        </label>
                    </div>
                    <div>
                        <input class="form-check-input" type="radio" name="sweet" value="Less" id="less">
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
                        <input class="form-check-input" type="radio" id="milk" value="Milk" name="dairy">
                        <label class="form-check-label" for="milk">
                            Milk
                        </label>
                    </div>
                    <div class="mx-2">
                        <input class="form-check-input" type="radio" name="dairy" value="Oat Milk" id="oatMilk">
                        <label class="form-check-label" for="oatMilk">
                            Oat Milk
                        </label>
                    </div>
                    <div>
                        <input class="form-check-input" type="radio" name="dairy" value="Almond Milk" id="almondMilk">
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
                            name="topping[]">
                        <label class="form-check-label" for="caramelSauce">
                            Caramel Sauce
                        </label>
                    </div>
                    <div class="mx-2">
                        <input class="form-check-input" type="checkbox" name="topping[]" value="Caramel Crumble"
                            id="caramelCrumble">
                        <label class="form-check-label" for="caramelCrumble">
                            Caramel Crumble
                        </label>
                    </div>
                    <div class="mx-2">
                        <input class="form-check-input" type="checkbox" name="topping[]" value="Choco Granola"
                            id="chocoGranola">
                        <label class="form-check-label" for="chocoGranola">
                            Choco Granola
                        </label>
                    </div>
                    <div class="mx-2">
                        <input class="form-check-input" type="checkbox" name="topping[]" value="Sea Salt Cream"
                            id="seaSaltCream">
                        <label class="form-check-label" for="seaSaltCream">
                            Sea Salt Cream
                        </label>
                    </div>
                </div>
            </div>
            <div class="mb-3">
                <label for="" class="form-label fw-bold">Note</label>
                <textarea class="form-control" placeholder="Write your additional note here" id="floatingTextarea"
                    name="note"></textarea>
            </div>
            <div class="mb-3">
                <button type="submit" class="btn btn-primary">Submit</button>
                <button type="reset" class="btn btn-danger">Reset</button>
            </div>
        </form>
    </div>
</body>

</html>