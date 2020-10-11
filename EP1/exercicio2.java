public class exercicio2 {

    public static void main(String[] args) {
        // Define a quantidade de threads a serem executadas
        // A quantidade pode ser passada como argumento na chamada do programa
        int totalThreads = 3;
        if(args[0] != null){
            totalThreads = Integer.parseInt(args[0]);
        }
        
        // Inicia as threads que exibirão a mensagem
        // A partir do momento que chamamos o método start() para uma determinada Thread
        // estamos entregando esta thread ao escalonador da JVM que se responsabilizará
        // por manter as threads paralelizadas
        for(int i = 0; i < totalThreads; i++){
            new Thread(runnable).start();
        }
    }

    // Cria um objeto da classe Runnable que possui o método run
    // O Runnable é uma interface da classe Thread
    private static Runnable runnable = new Runnable() {
        private int executingThreads = 0;

        public void run() {
            try {
                System.out.println("Hello World! - " + (++executingThreads));
            } catch (Exception exception) {
                exception.printStackTrace();
            }
        }
    };
}