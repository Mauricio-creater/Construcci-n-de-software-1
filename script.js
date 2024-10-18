let carrito = JSON.parse(localStorage.getItem('carrito')) || [];

function agregarAlCarrito(nombre, precio) {
    carrito.push({ nombre, precio });
    localStorage.setItem('carrito', JSON.stringify(carrito)); // Guardar el carrito en localStorage
    actualizarCarrito();
}

function actualizarCarrito() {
    const carritoList = document.getElementById('carrito');
    const totalElement = document.getElementById('total');
    carritoList.innerHTML = '';
    let total = 0;

    carrito.forEach(item => {
        const li = document.createElement('li');
        li.textContent = `${item.nombre} - $${item.precio.toFixed(2)}`;
        carritoList.appendChild(li);
        total += item.precio;
    });

    totalElement.textContent = `Total: $${total.toFixed(2)}`;
}

function cargarFactura() {
    const productosFactura = document.getElementById('productos-factura');
    const totalFactura = document.getElementById('total-factura');
    productosFactura.innerHTML = '';
    let total = 0;

    carrito.forEach(item => {
        const li = document.createElement('li');
        li.textContent = `${item.nombre} - $${item.precio.toFixed(2)}`;
        productosFactura.appendChild(li);
        total += item.precio;
    });

    totalFactura.textContent = `Total a Pagar: $${total.toFixed(2)}`;
}

// Función para guardar el recibo en el almacenamiento local
function guardarRecibo() {
    const recibo = {
        productos: [...carrito],
        total: carrito.reduce((acc, item) => acc + item.precio, 0)
    };

    let recibosGuardados = JSON.parse(localStorage.getItem('recibos')) || [];
    recibosGuardados.push(recibo);
    localStorage.setItem('recibos', JSON.stringify(recibosGuardados));

    alert("Recibo guardado exitosamente.");
    carrito = []; // Limpiar el carrito después de guardar
    actualizarCarrito(); // Actualizar la vista del carrito
}

// Cargar los productos en la página de facturación
if (window.location.href.includes('facturacion.html')) {
    cargarFactura();
}

// Cargar los recibos en la página de recibos
function cargarRecibos() {
    const recibosList = document.getElementById('recibos-lista');
    recibosList.innerHTML = '';
    const recibosGuardados = JSON.parse(localStorage.getItem('recibos')) || [];

    recibosGuardados.forEach((recibo, index) => {
        const li = document.createElement('li');
        li.textContent = `Compra ${index + 1}: Total - $${recibo.total.toFixed(2)}`;
        recibosList.appendChild(li);
    });
}

// Cargar recibos al abrir la página de recibos
if (window.location.href.includes('recibos.html')) {
    cargarRecibos();
}
