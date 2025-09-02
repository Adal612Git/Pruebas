const estudiantes = Array(10).fill(null);

function ingreso() {
  let posicion = 0;
  while (true) {
    const posStr = prompt("--------------------------------------\nLa tabla admite 10 estudiantes.\nIngrese la posición para registrar (1-10):\nEscriba 11 para volver al menú:");
    if (posStr === null) return; // Cancel -> exit to menu
    posicion = parseInt(posStr, 10);

    if (posicion === 11) break;
    if (isNaN(posicion) || posicion < 1 || posicion > 10) {
      alert("❌ Posición inválida. Intente de nuevo.");
      continue;
    }

    const idx = posicion - 1;
    const nombre = prompt("Ingrese el nombre:");
    if (nombre === null) continue;

    const edadStr = prompt("Ingrese la edad:");
    const edad = parseInt(edadStr, 10);

    const matricula = prompt("Ingrese la matrícula:");

    const promedioStr = prompt("Ingrese el promedio:");
    const promedio = parseFloat(promedioStr);

    estudiantes[idx] = { nombre, edad, matricula, promedio };
    alert(`✅ Estudiante registrado en posición ${posicion}.`);
  }
}

function consultar() {
  let message = "\n--- Consulta de Estudiantes ---\n";
  estudiantes.forEach((est, i) => {
    if (est) {
      message += `Posición ${i + 1}: Nombre: ${est.nombre}, Edad: ${est.edad}, Matrícula: ${est.matricula}, Promedio: ${est.promedio}\n`;
    }
  });
  message += "-----------------------------\n";
  alert(message);
}

function menu() {
  let opcion = 0;
  do {
    const opStr = prompt("\n______________________________________\nBienvenido, seleccione una opción:\n1. Ingresar estudiantes\n2. Consultar estudiantes\n3. Salir del programa\n--------------------------------------");
    if (opStr === null) break;
    opcion = parseInt(opStr, 10);

    switch (opcion) {
      case 1:
        ingreso();
        break;
      case 2:
        consultar();
        break;
      case 3:
        alert("Saliendo del programa.");
        break;
      default:
        alert("Opción inválida, intente de nuevo.");
    }
  } while (opcion !== 3);
}

menu();
