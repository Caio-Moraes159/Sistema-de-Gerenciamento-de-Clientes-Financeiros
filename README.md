<h1>Sistema de Gerenciamento de Clientes Financeiros</h1>

<p>Este projeto é um sistema de gerenciamento de clientes para uma empresa financeira. O programa permite cadastrar e gerenciar clientes, empréstimos e parcelas de forma eficiente. O sistema inclui um menu interativo que facilita a realização das seguintes operações:</p>

<ul>
    <li><strong>Cadastrar Cliente:</strong> Adiciona um novo cliente com informações como nome, CPF, endereço, data de nascimento, data do empréstimo, valor total do empréstimo e parcelas mensais.</li>
    <li><strong>Visualizar Informações de um Cliente:</strong> Exibe todos os detalhes de um cliente específico, incluindo parcelas e status de pagamento.</li>
    <li><strong>Editar Informações de um Cliente:</strong> Permite modificar os dados de um cliente existente.</li>
    <li><strong>Cadastrar Parcela Paga:</strong> Atualiza o status de uma parcela específica para indicar que foi paga.</li>
    <li><strong>Cadastrar Empréstimo:</strong> Registra um novo empréstimo associado a um cliente.</li>
    <li><strong>Excluir Cliente:</strong> Remove um cliente do sistema.</li>
    <li><strong>Sair:</strong> Encerra o programa.</li>
</ul>

<h2>Funcionalidades</h2>
<ul>
    <li><strong>Cadastro e Gestão de Clientes:</strong> Inclui informações pessoais, detalhes do empréstimo e parcelas.</li>
    <li><strong>Gerenciamento de Parcelas:</strong> Adiciona, visualiza e atualiza o status das parcelas do empréstimo.</li>
    <li><strong>Menu Interativo:</strong> Permite fácil acesso às principais funções do sistema.</li>
</ul>

<h2>Estrutura do Programa</h2>
<ul>
    <li><strong>Estruturas de Dados:</strong>
        <ul>
            <li><code>Parcela:</code> Armazena informações sobre cada parcela do empréstimo.</li>
            <li><code>Cliente:</code> Armazena informações pessoais e dados do empréstimo de um cliente, incluindo as parcelas.</li>
        </ul>
    </li>
    <li><strong>Funções Principais:</strong>
        <ul>
            <li><code>cadastrarCliente():</code> Adiciona um novo cliente ao sistema.</li>
            <li><code>visualizarCliente():</code> Exibe os dados de um cliente específico.</li>
            <li><code>editarCliente():</code> Atualiza informações de um cliente.</li>
            <li><code>cadastrarParcelaPaga():</code> Marca uma parcela como paga.</li>
            <li><code>cadastrarEmprestimo():</code> Registra um novo empréstimo.</li>
            <li><code>excluirCliente():</code> Remove um cliente do sistema.</li>
        </ul>
    </li>
</ul>

<h2>Como Compilar e Executar</h2>
<p>Para compilar e executar o programa, siga os passos abaixo:</p>
<ol>
    <li>Abra o terminal ou prompt de comando.</li>
    <li>Navegue até o diretório onde os arquivos <code>Trabalho_final2.cpp</code> estão localizados.</li>
    <li>Compile os arquivos usando o comando:
        <pre>
g++ Trabalho_final2.cpp -o gerenciamento
        </pre>
    </li>
    <li>Execute o programa com o comando:
        <pre>
./gerenciamento
        </pre>
    </li>
</ol>


<h2>Prompt do código quando executado</h2>
<p>Esse é o menu interativo que o ccódigo possui, se divirta usando ele e explorando suas possibilidades de uso:</p>

![image](https://github.com/user-attachments/assets/9dc343b3-f866-498f-80d6-7c162aba3267)

<h2>Licença</h2>
<p>Este projeto é licenciado sob os termos da licença MIT.</p>
