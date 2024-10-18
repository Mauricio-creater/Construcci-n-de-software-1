let carrito = [];

function agregarAlCarrito(nombre, precio) {
    carrito.push({ nombre, precio });
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

// Cargar los productos en la página de facturación
if (window.location.href.includes('facturacion.html')) {
    cargarFactura();
}
