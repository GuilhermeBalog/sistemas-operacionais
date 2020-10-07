public class exercicio2 {

    public static void main(String[] args) {
        // Inicia as threads que exibirão a mensagem
        // A partir do momento que chamamos o método start() para uma determinada Thread
        // estamos entregando esta thread ao escalonador da JVM que se responsabilizará
        // por manter as threads paralelizadas
        new Thread(runnable).start();
        new Thread(runnable).start();
        new Thread(runnable).start();
    }

    // Cria um objeto da classe Runnable que possui o método run
    // O Runnable é uma interface da classe Thread
    private static Runnable runnable = new Runnable() {
        public void run() {
            try {
                System.out.println("Hello World!");
            } catch (Exception exception) {
                exception.printStackTrace();
            }
        }
    };
}