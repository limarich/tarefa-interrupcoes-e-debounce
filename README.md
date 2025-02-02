# 🚀 Projeto: Controle de LEDs e Matriz 5x5 com RP2040

Este projeto implementa um **sistema de controle de LEDs e matriz de LEDs WS2812** utilizando a **placa BitDogLab com RP2040**. Ele emprega **interrupções**, **debouncing via software** e exibição de números de 0 a 9 na matriz de LEDs.

---

## 📜 **Descrição do Projeto**
O sistema é capaz de:
- Exibir números de 0 a 9 em uma **matriz de LEDs WS2812 (5x5)**.
- Alterar o número exibido **ao pressionar botões físicos (Botão A/B)**.
- Aplicar **debouncing via software** para evitar leituras incorretas dos botões.
- Piscar continuamente um **LED vermelho 5 vezes por segundo**.

**Tecnologias Utilizadas:**
- **C/C++**
- **Pico SDK**
- **Interrupções (IRQ)**
- **GPIO (RP2040)**
- **WS2812 (LEDs endereçáveis)**

---

## 🎯 **Objetivos**
✔️ Compreender e implementar interrupções no RP2040.  
✔️ Aplicar **debouncing via software** para evitar múltiplos acionamentos.  
✔️ Controlar LEDs individuais e **matrizes WS2812**.  
✔️ Criar um **projeto funcional** combinando hardware e software.  

---

## 🛠 **Hardware Utilizado**
- **Placa BitDogLab com RP2040**
- **Matriz de LEDs WS2812 (5x5)**
- **LED RGB (usando GPIOs 11, 12 e 13)**
- **Botão A (GPIO 5)**
- **Botão B (GPIO 6)**

---

## 📌 **Funcionalidades**
1️⃣ **Piscar o LED vermelho** (5Hz).  
2️⃣ **Botão A:** Incrementa o número exibido na matriz.  
3️⃣ **Botão B:** Decrementa o número exibido na matriz.  
4️⃣ **Matriz WS2812:** Mostra os números de 0 a 9.  

💡 **Extras:**  
- O código permite exibir os números na matriz **com cores aleatórias** quando o contador atinge **9**.  
- O uso de **interrupções garante uma resposta rápida e eficiente aos botões**.  

---

## 📺 Demonstração do Projeto
🎥 Link do Vídeo: [https://youtube.com/shorts/4olkr40GOcU?si=n6jt0XjU-PkaylH9]

