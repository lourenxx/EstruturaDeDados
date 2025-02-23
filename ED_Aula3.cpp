// LISTA 03 
// RHYU COSTA: 
// GUILHERME PEXIRILE LOURENCO: 082230011



#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

int PrecosCommodities();
int TaxaJuros();
int DadosEconomicos();
int RelatorioTrimestre();
int AnaliseEmpresas();
int AnaliseCarteiraInvestimentos();
int MediaMovelDemanda();
int AnaliseVariacaoCambial();
int PontoEquilibrio();
int ConversaoBase();

int main (){
    PrecosCommodities();
    TaxaJuros();
    DadosEconomicos();
    RelatorioTrimestre();
    AnaliseEmpresas();
    AnaliseCarteiraInvestimentos();
    MediaMovelDemanda();
    AnaliseVariacaoCambial();
    PontoEquilibrio();
    ConversaoBase();

    return 0;
}


// EXERCICIO 1

int PrecosCommodities(){

    struct  Commodity
    {
        string nome;
        double preco;
    };
    
    Commodity commodities[5] = {
    {"Petroleo", 75.50},
    {"Ouro", 1800}, 
    {"Prata", 25.30}, 
    {"Trigo",7.80}, 
    {"Cafe",2.10}
    };

    double max_value = (commodities[0].preco);
    double min_value = (commodities[0].preco);
    double sum = 0;

    for (int i = 0; i < 5; i++)
    {
        max_value = max(max_value, commodities[i].preco);

    }

    for (int i = 0; i < 5; i++)
    {
        min_value = min(min_value, commodities[i].preco);

    }

    for (int i = 0; i < 5; i++)
    {
        sum += commodities[i].preco;
    }
    
    double media = sum / 5;

    cout << "Valor Maximo -> " << max_value << endl;

    cout << "Valor Minimo -> " << min_value << endl;

    cout << "Media dos Precos -> " << media << "\n" << endl;

    
    return 0;
    

}

// EXERCICIO 2

int TaxaJuros(){



    double taxaJuros[12] = {6.5, 6.7, 6.8, 7.0, 7.2, 7.5, 7.4, 7.3, 7.1, 6.9, 6.8, 6.7};

    int tamanhoVetor = sizeof(taxaJuros) / sizeof(taxaJuros[0]);
    
    int mes = 0;
    int mesMaiorJuros = 0;
    int mesMenorJuros = 1;
    double maiorTaxa = taxaJuros[0];
    double menorTaxa = taxaJuros[0];


    for(int i = 1; i < tamanhoVetor; i++){
        if(taxaJuros[i] > maiorTaxa){
            maiorTaxa = taxaJuros[i];
            mesMaiorJuros = i+1;
        }

    }

    
    cout << "Mes com MAIOR taxa de juros -> " << mesMaiorJuros << " : " << maiorTaxa << "%" << endl;

        for(int i = 1; i < tamanhoVetor; i++){
        if(taxaJuros[i] < menorTaxa){
            menorTaxa = taxaJuros[i];
            mesMenorJuros = i+1;
        }

    }

    cout << "Mes com MENOR taxa de juros -> " << mesMenorJuros << " : " << menorTaxa << "%" << endl;

    

    for (int i = 1; i < tamanhoVetor; i++){

        double variacaoPercentual = ((taxaJuros[i] - taxaJuros[i-1])/taxaJuros[i-1])*100;
        mes = i+1;

        cout << "Variacao Percentual do mes " << mes << ": " << variacaoPercentual << endl;

        }

        cout << "\n" << endl;

}


//EXERCÍCIO 3

int DadosEconomicos(){

    struct DadosEconomicosPaises {
        string pais;
        double pib;
        double taxaInflacao;
        double taxaDesemprego;
    };

    DadosEconomicosPaises dadosPaises[5] = {

        {"Estados Unidos", 25.3, 3.7, 4.2},
        {"Brasil", 1.6, 5.2, 9.3,},
        {"Alemanha", 4.2, 2.1, 3.0},
        {"Japao", 5.0, 0.5, 2.6,},
        {"India", 3.1, 6.1, 7.1}

    };

    double maiorPib = (dadosPaises[0].pib);
    string paisMaiorPib = (dadosPaises[0].pais);
    double somaInflacao = 0; 

    for(int i = 0; i < 5; i++){
        if(dadosPaises[i].pib > maiorPib){
            maiorPib = dadosPaises[i].pib;
            paisMaiorPib = dadosPaises[i].pais;
        }
    }
    
    cout << "O pais com maior pib eh a/o " << paisMaiorPib << " com " << maiorPib << " Trilhoes de USD" << "\n"  << endl;

    for(int i = 0; i < 5; i++){
        
        
        somaInflacao += dadosPaises[i].taxaInflacao;
    }

    double mediaInflacao = somaInflacao/5;

    cout << "Media da Inflacao: " << mediaInflacao << "%" << endl;

    return 0; 
}

//EXERCÍCIO 4

int RelatorioTrimestre() {

    struct DadosTrimestre {
        string trimestre;
        double pib;
        int exportacoes;
        int importacoes;
    };

    DadosTrimestre dadosTrimestre[4] = {
        {"1 Trimestre", 2.5, 500, 450},
        {"2 Trimestre", 2.7, 520, 470},
        {"3 Trimestre", 2.8, 530, 480},
        {"4 Trimestre", 3.0, 550, 500},
    };

    // Cálculo do crescimento do PIB trimestral
    cout << "Crescimento do PIB Trimestral:" << endl;
    for (int i = 1; i < 4; i++) {
        double crescimento = ((dadosTrimestre[i].pib - dadosTrimestre[i-1].pib) / dadosTrimestre[i-1].pib) * 100;
        cout << dadosTrimestre[i].trimestre << ": " << crescimento << "%" << endl;
    }
    
    // Cálculo da média anual das exportações e importações
    double somaExportacoes = 0, somaImportacoes = 0;
    for (int i = 0; i < 4; i++) {
        somaExportacoes += dadosTrimestre[i].exportacoes;
        somaImportacoes += dadosTrimestre[i].importacoes;
    }

    double mediaExportacoes = somaExportacoes / 4;
    double mediaImportacoes = somaImportacoes / 4;

    cout << "\nSumario Economico do Ano:" << endl;
    cout << "Media de Exportacoes: " << mediaExportacoes << " bilhoes" << endl;
    cout << "Media de Importacoes: " << mediaImportacoes << " bilhoes" << endl;

    return 0;
}

// EXERCICIO 5

int AnaliseEmpresas() {

    struct Empresa {
        string nome;
        double precoAcao;
        int volumeNegociado;
        double capitalizacaoMercado;
    };

    Empresa empresas[5] = {
        {"Empresa A", 150.75, 5000000, 75.5},
        {"Empresa B", 80.30, 3000000, 30.8},
        {"Empresa C", 210.10, 7000000, 150.2},
        {"Empresa D", 50.25, 2000000, 10.5},
        {"Empresa E", 120.60, 4000000, 55.7}
    };

    // Determinar o menor e o maior volume negociado
    int minVolume = empresas[0].volumeNegociado;
    int maxVolume = empresas[0].volumeNegociado;

    for (int i = 1; i < 5; i++) {
        if (empresas[i].volumeNegociado < minVolume) {
            minVolume = empresas[i].volumeNegociado;
        }
        if (empresas[i].volumeNegociado > maxVolume) {
            maxVolume = empresas[i].volumeNegociado;
        }
    }

    // Gerar um valor aleatório entre o menor e o maior volume negociado
    srand(time(0));
    int valorAleatorio = minVolume + rand() % (maxVolume - minVolume + 1);

    cout << "Valor aleatorio de referencia para capitalizacao de mercado: " << valorAleatorio << " milhoes" << endl;
    cout << "\nEmpresas com capitalizacao de mercado acima de " << valorAleatorio << " milhoes:" << endl;

    bool encontrou = false;
    for (int i = 0; i < 5; i++) {
        if (empresas[i].capitalizacaoMercado > valorAleatorio) {
            cout << empresas[i].nome << " - Capitalizacao de Mercado: " << empresas[i].capitalizacaoMercado << " bilhoes" << endl;
            encontrou = true;
        }
    }

    if (!encontrou) {
        cout << "Nenhuma empresa atende ao criterio." << endl;
    }

    return 0;
}


// EXERCICIO 6

int AnaliseCarteiraInvestimentos() {

    struct Ativo {
        string nome;
        double precoCompra;
        int quantidade;
        double precoAtual;
    };

    Ativo carteira[5] = {
        {"Acao A", 50.0, 100, 55.0},
        {"Acao B", 30.5, 200, 28.0},
        {"Acao C", 75.2, 150, 80.0},
        {"Acao D", 120.0, 50, 130.0},
        {"Acao E", 15.0, 300, 18.5}
    };

    double valorTotalInvestido = 0;
    double valorTotalAtual = 0;

    for (int i = 0; i < 5; i++) {
        valorTotalInvestido += carteira[i].precoCompra * carteira[i].quantidade;
        valorTotalAtual += carteira[i].precoAtual * carteira[i].quantidade;
    }

    double retornoPercentual = ((valorTotalAtual - valorTotalInvestido) / valorTotalInvestido) * 100;

    cout << "Valor total investido: " << valorTotalInvestido << " reais" << endl;
    cout << "Valor total atual da carteira: " << valorTotalAtual << " reais" << endl;
    cout << "Retorno total da carteira: " << retornoPercentual << "%" << endl;

    return 0;
}


// EXERCICIO 7

int MediaMovelDemanda() {
    
    int demandaMensal[12] = {120, 150, 170, 160, 180, 200, 220, 210, 230, 250, 270, 260};

    int periodo;
    cout << "Digite o periodo para calcular a media movel (exemplo: 3 meses): ";
    cin >> periodo;

    if (periodo <= 0 || periodo > 12) {
        cout << "Periodo invalido!" << endl;
        return 0;
    }

    cout << "Media movel para " << periodo << " meses:" << endl;
    for (int i = 0; i <= 12 - periodo; i++) {
        double soma = 0;
        for (int j = 0; j < periodo; j++) {
            soma += demandaMensal[i + j];
        }
        double media = soma / periodo;
        cout << "Mes " << (i + periodo) << ": " << media << endl;
    }

    return 0;
}


// EXERCICIO 8

int AnaliseVariacaoCambial() {
    
    double moedaBase[7] = {5.10, 5.12, 5.15, 5.13, 5.18, 5.20, 5.22};
    double moedaComparacao[7] = {1.10, 1.12, 1.14, 1.11, 1.13, 1.16, 1.18};

    double variacao[6];
    double maiorVariacao = 0, menorVariacao = 100;
    int diaMaior = 0, diaMenor = 0;

    for (int i = 1; i < 7; i++) {
        variacao[i - 1] = ((moedaComparacao[i] - moedaComparacao[i - 1]) / moedaComparacao[i - 1]) * 100;

        if (variacao[i - 1] > maiorVariacao) {
            maiorVariacao = variacao[i - 1];
            diaMaior = i;
        }
        if (variacao[i - 1] < menorVariacao) {
            menorVariacao = variacao[i - 1];
            diaMenor = i;
        }
    }

    cout << "Variacao percentual diaria da moeda:" << endl;
    for (int i = 0; i < 6; i++) {
        cout << "Dia " << i + 1 << ": " << variacao[i] << "%" << endl;
    }

    cout << "Maior variacao: Dia " << diaMaior << " com " << maiorVariacao << "%" << endl;
    cout << "Menor variacao: Dia " << diaMenor << " com " << menorVariacao << "%" << endl;

    return 0;
}


// EXERCICIO 9

int PontoEquilibrio() {
    
    double custoFixo, precoVenda, custoVariavel;
    
    cout << "Digite o custo fixo total: ";
    cin >> custoFixo;
    
    cout << "Digite o preco de venda por unidade: ";
    cin >> precoVenda;
    
    cout << "Digite o custo variavel por unidade: ";
    cin >> custoVariavel;

    if (precoVenda <= custoVariavel) {
        cout << "Nao e possivel atingir o ponto de equilibrio com esses valores!" << endl;
        return 0;
    }

    int unidadesEquilibrio = custoFixo / (precoVenda - custoVariavel);

    cout << "Quantidade necessaria para atingir o ponto de equilibrio: " << unidadesEquilibrio << " unidades" << endl;

    return 0;
}


// EXERCICIO 10

int ConversaoBase() {
    
    int opcao;
    cout << "Escolha a conversao desejada: " << endl;
    cout << "1 - Decimal para Binario" << endl;
    cout << "2 - Binario para Decimal" << endl;
    cin >> opcao;

    if (opcao == 1) {
        int numeroDecimal;
        cout << "Digite um numero decimal: ";
        cin >> numeroDecimal;

        int binario[32];
        int i = 0;
        while (numeroDecimal > 0) {
            binario[i] = numeroDecimal % 2;
            numeroDecimal /= 2;
            i++;
        }

        cout << "Binario: ";
        for (int j = i - 1; j >= 0; j--) {
            cout << binario[j];
        }
        cout << endl;

    } else if (opcao == 2) {
        int numeroBinario, numeroDecimal = 0, base = 1;
        cout << "Digite um numero binario: ";
        cin >> numeroBinario;

        while (numeroBinario > 0) {
            int ultimoDigito = numeroBinario % 10;
            numeroDecimal += ultimoDigito * base;
            numeroBinario /= 10;
            base *= 2;
        }

        cout << "Decimal: " << numeroDecimal << endl;
    } else {
        cout << "Opcao invalida!" << endl;
    }

    return 0;
}



