# 📚 Academic Life - Systems Analysis and Design

[![Universidad Distrital](https://img.shields.io/badge/Universidad-Distrital-green.svg)](https://www.udistrital.edu.co/)
[![Course](https://img.shields.io/badge/Course-Systems%20Analysis%20%26%20Design-blue.svg)]()
[![Status](https://img.shields.io/badge/Status-Active-brightgreen.svg)]()
[![License: Academic](https://img.shields.io/badge/License-Academic-yellow.svg)]()

> **Complete academic documentation for Systems Analysis and Design course at Universidad Distrital Francisco José de Caldas**

This repository contains the theoretical foundations, architectural designs, quality frameworks, and project management documentation for the **Forest Cover Type Prediction** system. It represents the evolution of a machine learning project from systems analysis through production-ready architecture.

🚀 **Implementation Repository**: For the complete working code, trained models, and deployment files, see the [Forest Type Prediction Repository](https://github.com/nikkaoyy/Forest-Type-Prediction).

---

## 📋 Table of Contents

- [Overview](#overview)
- [Repository Structure](#repository-structure)
- [Workshop Progression](#workshop-progression)
- [Key Contributions](#key-contributions)
- [Theoretical Foundations](#theoretical-foundations)
- [Architecture Evolution](#architecture-evolution)
- [Quality Frameworks](#quality-frameworks)
- [Project Management](#project-management)
- [Cross-Repository Integration](#cross-repository-integration)
- [Team](#team)
- [Academic Context](#academic-context)

---

## 🎯 Overview

This repository documents the **academic journey** of designing a production-grade ML system for forest cover classification. It showcases the application of systems engineering principles, quality management frameworks, and chaos theory to real-world ecological prediction using LightGBM.

### What's Inside?

- ✅ **3 Workshop Reports** (PDF + LaTeX sources)
- ✅ **Systems Analysis** - Chaos theory, sensitivity analysis, vulnerability assessment
- ✅ **Architecture Design** - 7-layer conceptual → 4-layer production evolution
- ✅ **Quality Standards** - ISO 9000, CMMI Level 3, Six Sigma alignment
- ✅ **Risk Management** - 8 critical risks with mitigation strategies
- ✅ **Model Selection Rationale** - Why LightGBM was chosen over ensemble approaches
- ✅ **Project Management** - Agile-Kanban methodology, team roles, timelines

### Academic Learning Outcomes

1. **Systems Thinking**: Identify elements, relationships, and emergent behaviors in complex systems
2. **Chaos Theory Application**: Detect sensitivity zones and quantify uncertainty
3. **Architecture Design**: Apply modularity, loose coupling, separation of concerns
4. **Quality Management**: Align with international standards (ISO, CMMI, Six Sigma)
5. **Risk Analysis**: Systematic identification, assessment, and mitigation
6. **Project Management**: Hybrid Agile-Kanban execution with traceability

---

## 📁 Repository Structure

```
Academic-Life/
├── Systems-Analysis/
│   ├── Workshops/
│   │   ├── Workshop1/
│   │   │   ├── Workshop1_Systems Analysis of Kaggle's Forest Cover Type.pdf
|   |   |   ├── Work1_Summary.md
│   │   │   └── diagrams/              # Diagrams and charts
│   │   │
│   │   ├── Workshop2/
│   │   │   ├── Workshop2__Systems Analysis of Kaggles Forest Cover Type Prediction Elements Relationships Sensitivity and Chaos.pdf
│   │   │   ├── diagrams/
│   │   │   │   ├── Appendix1_CoreArchitecturalDiagram.drawio.pdf
│   │   │   │   └── Appendix2_ModuleInteraction&DataFlow.pdf
│   │   │   └── Work2_Summary.md
│   │   │
│   │   └── Workshop3/
│   │       ├── Workshop3_Robust_System_Management.pdf
│   │       ├── diagrams/
│   │       │   └── ForestArchitecture.drawio.pdf
│   │       └── Work3_Summary.md
│
├── Other_Courses/
│   ├── Computer Science/
│   ├── Advanced Programming/
│   └── ...
│
├── README.md                         
└── LICENSE
```

---

## 📖 Workshop Progression

### Workshop 1: Systems Analysis - Elements, Relationships, Sensitivity, and Chaos
**Date**: October 2024  
**Focus**: Foundational systems analysis and chaos detection

**Key Deliverables**:
1. ✅ **System Decomposition**
   - Input Layer: 54 cartographic features (10 numerical, 4 wilderness, 40 soil types)
   - Processing Layer: Multi-class classification (7 cover types)
   - Output Layer: Species predictions with ecological interpretation

2. ✅ **Critical Relationships Identified**
   - Elevation as master environmental driver (3 climatic zones)
   - Aspect-elevation coupling with nonlinear interactions
   - Distance metrics creating spatial network effects

3. ✅ **Vulnerability Assessment**
   - Soil type sparsity: 73% zeros across 40 binary indicators
   - Temporal brittleness: Single-timepoint snapshot lacks seasonal variation
   - Geographic overfitting risk: Colorado Front Range specialization

4. ✅ **Chaos Theory Findings**
   - **Elevation threshold effects**: Sharp transitions at 2400m, 2800m, 3000m
   - **Butterfly effect**: ±50m elevation changes trigger complete species replacement
   - **Sensitive dependence**: 19.6% of observations in chaotic transition zones

**Impact**: Established the theoretical foundation for all subsequent design decisions.

---

### Workshop 2: System Design and Architecture
**Date**: November 2024  
**Focus**: Translating analysis into implementable architecture

**Key Deliverables**:
1. ✅ **Seven-Layer Conceptual Architecture**
   - Layer 1: Data Ingestion (USGS, GeoTIFF)
   - Layer 2: Validation (schema, outliers, autocorrelation)
   - Layer 3: Feature Engineering (4 specialized modules)
   - Layer 4: Model Training (ensemble optimization)
   - Layer 5: Uncertainty Quantification (aleatoric + epistemic)
   - Layer 6: Monitoring (drift detection, KL-divergence)
   - Layer 7: Deployment (FastAPI + batch processing)

2. ✅ **Feature Engineering Modules**
   - **Module 3A**: Elevation binning with chaos detection
   - **Module 3B**: Circular aspect encoding (sin/cos)
   - **Module 3C**: Soil consolidation (40 → 15 groups)
   - **Module 3D**: Distance interactions and normalization

3. ✅ **Ensemble Design → LightGBM Selection**
   - Initial ensemble design: Random Forest + XGBoost + LightGBM (weights: 0.3, 0.4, 0.3)
   - Performance analysis showed LightGBM alone achieved 95%+ accuracy
   - Decision to simplify: Single LightGBM model for production
   - **Rationale**: Faster inference, smaller model size, easier maintenance
   - **Trade-off**: Slightly lower robustness vs ensemble, but significant operational gains
   - **Theoretical accuracy**: 95.2% (maintained from ensemble design)

4. ✅ **Chaos Control Mechanisms**
   - Threshold proximity detector (±50m windows)
   - 2× uncertainty amplification near transition zones
   - Dual uncertainty decomposition (aleatoric vs epistemic)

**Visualization Perspectives**:
- Layered pipeline diagram
- Component dependency graph
- Data flow sequences
- Module interaction matrix
- Ecological alignment scheme

---

### Workshop 3: Robust System and Quality Management
**Date**: November-December 2024  
**Focus**: Production-ready architecture with quality frameworks

**Key Deliverables**:
1. ✅ **Architecture Consolidation**: 7 layers → 4 layers
   - **Data Gate**: Ingestion + validation with circuit breaker
   - **Preprocessing / Feature Engineer**: Unified Column Transformer
   - **Model Training and Evaluation**: Quality gates preventing regression
   - **Uncertainty / Decision / Models**: Chaos-aware inference core

2. ✅ **Quality Objectives & Standards**
   - **ISO 9000**: Process-oriented QMS with artifact versioning (MLflow)
   - **ISO/IEC 27001**: ISMS with RBAC, encryption, audit logs
   - **CMMI Level 3**: Standardized processes with cross-validation protocols
   - **Six Sigma**: Statistical process control (accuracy drift, KL-divergence)

3. ✅ **Risk Register (8 Critical Risks)**

   | ID | Risk | Probability | Impact | Mitigation |
   |----|------|-------------|--------|------------|
   | R1 | Chaotic elevation thresholds | High | High | Threshold-proximity detector with 2× uncertainty amplification |
   | R2 | Soil-type sparsity & overfitting | Medium | High | Consolidate to 15 groups, elevation-blocked CV |
   | R3 | Geographic/temporal brittleness | High | Medium | Document scope, drift-triggered retraining |
   | R4 | Data & concept drift | Medium | High | KL-divergence surveillance, PSI alerts |
   | R5 | Reproducibility variance | Medium | Medium | 5-fold CV, fixed seeds, bounded HPO |
   | R6 | Service latency/availability | Low | High | Redis caching, Kubernetes scaling |
   | R7 | Data loss & downtime | Low | Critical | S3 storage, MLflow lineage, checkpoints |
   | R8 | Security & compliance | Medium | High | RBAC, encryption, audit trails |

4. ✅ **Operational KPIs**
   - **Accuracy**: Target 95.2%, alert if drop ≥5%
   - **Latency**: p95 <100ms, p99 <200ms
   - **Availability**: 99.9% SLA
   - **Drift**: KL-divergence threshold 0.01 (minor), 0.05 (major)
   - **Chaos Zone Frequency**: Alert if >20% predictions in threshold zones

5. ✅ **Project Management - Hybrid Agile-Kanban**
   - **Team Roles**: Project Manager, Data Analyst, ML Engineer, Backend Developer, QA Manager
   - **Milestones**: 5 phases over 5 weeks (Nov 3 - Dec 6, 2024)
   - **Tools**: GitHub Projects, Notion, MLflow, Grafana
   - **Methodology**: Weekly stand-ups, feature branches, code reviews

**Evidence of Improvement**:
- Achieved 95%+ accuracy with single LightGBM model (vs. 95.2% ensemble target)
- Reduced model complexity: 1 model vs. 3 models (training time ↓40%, storage ↓65%)
- Maintained chaos zone performance with uncertainty quantification
- Simplified deployment: Single model artifact vs. ensemble management
- Feature engineering remains intact: 56 → 15-20 features (sparsity 73% → 5%)

---

## 🔑 Key Contributions

### 1. Model Selection: From Ensemble to LightGBM

**Initial Design (Workshops 1-2)**:
- Theoretical ensemble: Random Forest + XGBoost + LightGBM
- Weighted voting with [0.3, 0.4, 0.3] weights
- Target: 95.2% accuracy through model diversity

**Final Implementation (Workshop 3)**:
- Single LightGBM model
- Simplified architecture without ensemble complexity
- Achieved: 95%+ accuracy (maintained performance target)

**Decision Rationale**:

| Aspect | Ensemble Approach | LightGBM Only | Winner |
|--------|------------------|---------------|--------|
| Accuracy | 95.2% | 95%+ | ≈ Tie |
| Training Time | ~180s (3 models) | ~35s | ✅ LightGBM |
| Inference Speed | ~100ms | ~50ms | ✅ LightGBM |
| Model Size | ~15MB | ~2.3MB | ✅ LightGBM |
| Maintenance | Complex | Simple | ✅ LightGBM |
| Memory Usage | ~3GB | ~1GB | ✅ LightGBM |

**Key Insight**: 
> "Model simplicity is a feature, not a bug. LightGBM's gradient boosting efficiently captures the feature interactions that motivated the original ensemble design, while eliminating operational overhead."

**Academic Learning**:
- Ensemble design taught us to analyze complementary model strengths
- Performance testing revealed when complexity doesn't add value
- Production constraints (latency, memory) drive architectural decisions
- **Systems thinking**: Optimize for total cost of ownership, not just accuracy

### 2. Chaos Theory Integration in ML

**Problem**: Traditional ML assumes smooth decision boundaries and stable feature-target relationships.

**Our Approach**:
- Identify ecological "phase transitions" where small input changes cause large output shifts
- Quantify sensitive dependence using elevation threshold proximity
- Amplify uncertainty predictions 2× near transition zones (2400m, 2800m, 3200m)

**Formulas**:

**Aleatoric Uncertainty (Entropy)**:
```
H = -Σ p_i log₂(p_i)
U_aleatoric = H / log₂(7)
```

**Epistemic Uncertainty (Model Disagreement)**:
```
U_epistemic = √(1/3 Σ(p_model - p̄)²)
```

**Total Uncertainty with Chaos Amplification**:
```
U_total = √(U_aleatoric² + U_epistemic²)
IF near_threshold: U_total *= 2.0
```

**Impact**: Provides ecologists with actionable confidence metrics for field verification decisions. Works seamlessly with LightGBM's probability outputs.

---

### 3. Systems Engineering Principles Applied

**Modularity**:
- 4 independently deployable layers (Data Gate, Feature Engineering, Model Training, Inference)
- Each module has well-defined input/output contracts
- Enables parallel development without dependency conflicts

**Separation of Concerns**:
- Data validation isolated from feature engineering
- Model training decoupled from inference logic
- Uncertainty quantification operates independently

**Loose Coupling**:
- Inter-module communication via versioned artifacts (.pkl, .npy, .json)
- Technology substitution without code refactoring (e.g., XGBoost → CatBoost)

**Fault Tolerance**:
- Circuit breaker pattern in validation layer
- Automated F1-score comparison prevents model regression
- Graceful degradation in ensemble inference (reweight if model fails)

---

### 4. Feature Engineering Innovation

**Module 3C: Soil Consolidation**
- **Challenge**: 40 sparse binary soil types (73% zeros)
- **Solution**: Consolidate into 15 ecologically coherent groups
- **Result**: Sparsity reduced to 5%, dimensionality↓, overfitting risk↓

**Consolidation Strategy**:
```python
SOIL_GROUPS = {
    'Sandy_Soils': [7, 8, 11, 15, 25],
    'Clay_Soils': [1, 2, 3, 4, 5, 6, 9, 13],
    'Rocky_Soils': [16, 17, 18, 19, 20, 21, 22, 23, 26, 27],
    'Organic_Soils': [28, 30, 31, 32, 33, 35],
    'Other_Soils': [34, 36, 37, 38, 39, 40]
}
```

**Impact**: 40% faster training, improved generalization, maintained ecological interpretability. LightGBM efficiently handles the consolidated feature space.

---

## 🏛️ Theoretical Foundations

### Chaos Theory in Forest Ecosystems

**Lorenz's Sensitive Dependence**:
> "Small differences in initial conditions (such as those due to rounding errors in numerical computation) yield widely diverging outcomes for chaotic systems" — Edward Lorenz (1963)

**Application to Forest Cover**:
- Elevation thresholds (2400m, 2800m, 3200m) act as **ecological attractors**
- Within ±50m windows, classification uncertainty amplifies dramatically
- Deterministic rules blur into **chaotic species mixing**

**Butterfly Effect Manifestation**:
- ±50m elevation error → Complete community replacement
- Aspect orientation (north vs south at 2800m) → Different species dominance

### Sensitivity Analysis

**Global Sensitivity (Saltelli et al., 2008)**:
```
S_i = Var(E[Y | X_i]) / Var(Y)
```
Where:
- `S_i`: Sensitivity index for feature `i`
- `Y`: Model output (predicted class)
- `X_i`: Input feature (e.g., elevation)

**Our Findings** (LightGBM Feature Importance):
- Elevation: 0.342 (highest sensitivity)
- Horizontal_Distance_To_Hydrology: 0.128
- Wilderness_Area3: 0.095

---

## 🏗️ Architecture Evolution

### Phase 1: Conceptual Design (Workshop 2)
**7-Layer Pipeline**
- Comprehensive theoretical coverage
- Clear separation of data → model → deployment
- Foundation for all subsequent iterations

### Phase 2: Production Refinement (Workshop 3)
**4-Layer Consolidated Architecture**
- Merged related layers for operational efficiency
- Added fault tolerance mechanisms (circuit breaker, quality gates)
- Embedded chaos detection directly into inference pipeline
- **Simplified to single LightGBM model** (eliminated ensemble complexity)

**Key Improvements**:
1. **Data Gate** (Layers 1+2): Single entry point with schema validation + drift detection
2. **Feature Engineering** (Layer 3): Column Transformer with SMOTEENN balancing
3. **Model Training** (Layer 4): LightGBM with automated performance validation
4. **Inference Core** (Layers 5+6+7): Real-time uncertainty + monitoring + deployment

**Design Evolution**:
- Workshop 2: Ensemble of 3 models (RF + XGBoost + LightGBM)
- Workshop 3: Single LightGBM model after performance analysis
- **Rationale**: 95%+ accuracy maintained with 65% less storage, 60% faster inference

**Design Principle**: "Reduced complexity and enhanced fault tolerance are not competing objectives but complementary qualities achieved through thoughtful design."

---

## 📊 Quality Frameworks

### ISO 9000: Quality Management System

**Implementation**:
- ✅ Process documentation (feature engineering SOPs, CV protocols)
- ✅ Artifact versioning (MLflow tracking)
- ✅ Audit logging (PostgreSQL for all predictions)
- ✅ Continuous improvement cycles (retraining triggers)

**Evidence**: Complete transformation pipeline (`preprocessor.pkl`) with configuration manifests.

---

### CMMI Level 3: Defined Processes

**Maturity Level Characteristics**:
- Processes are well-characterized and understood
- Standards, procedures, tools, and methods documented
- Tailoring from organization's standard processes

**Our Implementation**:
- Standardized feature engineering modules (3A, 3B, 3C, 3D)
- Cross-validation with elevation-aware stratification
- Deployment gates enforce regression testing
- Metrics-driven governance (accuracy drift, KL-divergence)

---

### Six Sigma: DMAIC Cycle

**Define**: Prediction errors as defects (target accuracy 95.2%)  
**Measure**: Track KL-divergence, PSI, per-class accuracy  
**Analyze**: Root cause analysis for performance degradation (topographic bias, imbalance)  
**Improve**: Feature re-engineering, HPO, uncertainty threshold adjustments  
**Control**: Continuous monitoring, automated retraining, rollback capabilities  

**Process Control Charts**:
- Accuracy drift (control limit: ±3%)
- KL-divergence (threshold: 0.01 minor, 0.05 major)
- Confidence decay (alert: >3% weekly decline)

---

## 📅 Project Management

### Team Structure

| Role | Name | Responsibilities |
|------|------|------------------|
| **Project Manager / System Architect** | Nicolás Martínez Pineda | Planning, alignment, milestones, documentation |
| **Data Analyst / Feature Engineer** | Jean Paul Contreras Talero | Preprocessing, transformations, sensitivity monitoring |
| **Machine Learning Engineer** | Nicolás Martínez Pineda | Model training, HPO, ensemble optimization |
| **Backend & MLOps Developer** | Gabriel Esteban Gutiérrez Calderón | FastAPI, Redis, PostgreSQL, Grafana dashboards |
| **Quality & Risk Manager** | Anderson Danilo Martínez Bonilla | Code reviews, risk tracking, ISO/CMMI compliance |

### Methodology: Hybrid Agile-Kanban

**Why Hybrid?**
- **Agile**: Flexibility for research iterations (model experimentation)
- **Kanban**: Delivery stability through visualized workflows and cycle time monitoring
- **Quality Gates**: Automated model evaluation prevents regression (CMMI Level 3)

**Workflow Stages**:
1. **To Do**: Backlog with prioritization (chaos zone handling = P0)
2. **In Progress**: WIP limits (2 tasks per person max)
3. **Review**: Code review + testing (≥1 approval required)
4. **Done**: Merged to main, artifacts versioned

**Tools**:
- GitHub Projects (Kanban board)
- Notion (Design decisions, runbooks)
- MLflow (Experiment tracking)
- Grafana (Production monitoring)

### Timeline (5 Weeks)

```
Week 1 (Nov 3-9):   Architecture refinement + detailed planning
Week 2 (Nov 10-16): Data validation + feature engineering
Week 3 (Nov 17-23): Ensemble model integration + performance testing
Week 4 (Nov 24-30): Deployment setup + monitoring configuration
Week 5 (Dec 1-6):   Final documentation, review, project delivery
```

**Milestones**:
- ✅ Phase 1: Architecture Review (Nov 8, 2025)
- ✅ Phase 2: Data Validation & Feature Engineering (Nov 15, 2025)
- ✅ Phase 3: Model Integration and Optimization (Nov 22, 2025)
- ✅ Phase 4: Deployment and Monitoring (Nov 29, 2025)
- ✅ Phase 5: Final Documentation (Dec 6, 2025)

---

## 🔗 Cross-Repository Integration

### How Repositories Connect

```
┌─────────────────────────────────────────────────────────────┐
│                    ACADEMIC LIFE REPOSITORY                 │
│                 (Systems Analysis & Design)                 │
│                                                             │
│  ┌──────────────┐  ┌──────────────┐  ┌──────────────┐    │
│  │  Workshop 1  │  │  Workshop 2  │  │  Workshop 3  │    │
│  │   Analysis   │→ │ Architecture │→ │   Quality    │    │
│  │   & Chaos    │  │    Design    │  │  Management  │    │
│  └──────┬───────┘  └──────┬───────┘  └──────┬───────┘    │
│         │                  │                  │            │
│         └──────────────────┼──────────────────┘            │
│                            │                               │
│                   THEORETICAL FOUNDATION                   │
│                  (PDFs, LaTeX, Diagrams)                   │
└────────────────────────────┼──────────────────────────────┘
                             │
                             │ INFORMS
                             ↓
┌─────────────────────────────────────────────────────────────┐
│              FOREST TYPE PREDICTION REPOSITORY              │
│                  (Kaggle Competition Code)                  │
│                                                             │
│  ┌──────────────┐  ┌──────────────┐  ┌──────────────┐    │
│  │ Preprocessing│  │   Training   │  │     API      │    │
│  │   Pipeline   │→ │   Ensemble   │→ │  Deployment  │    │
│  │   (Modules)  │  │  (RF+XGB+LGB)│  │  (FastAPI)   │    │
│  └──────────────┘  └──────────────┘  └──────────────┘    │
│                                                             │
│                   IMPLEMENTATION ARTIFACTS                  │
│           (Code, Models, Tests, Docker, Notebooks)          │
└─────────────────────────────────────────────────────────────┘
```

### Reference Examples

**In Academic Life README**:
```markdown
For the complete working implementation with trained models:
👉 [Forest Type Prediction Repository](https://github.com/nikkaoyy/Forest-Type-Prediction)
```

**In Forest Type Prediction README**:
```markdown
This project implements the architecture documented in:
📚 [Academic Life - Systems Analysis](https://github.com/nikkaoyy/Academic-Life)
```

**In Workshop PDFs** (Workshop 3, Section VI):
```latex
\section{Implementation Repository}
The production code implementing this architecture is available at:
\url{https://github.com/nikkaoyy/Forest-Type-Prediction}

\noindent Key artifacts include:
\begin{itemize}
    \item \texttt{preprocessor.pkl}: Feature engineering pipeline (Modules 3A-3D)
    \item \texttt{ensemble\_models.pkl}: Trained RF + XGBoost + LightGBM
    \item \texttt{api/app.py}: FastAPI inference endpoint with uncertainty quantification
\end{itemize}
```

---

## 👥 Team

**Authors**:
- **Nicolás Martínez Pineda** (20241020098) - Project Manager, ML Engineer
- **Anderson Danilo Martínez Bonilla** (20241020107) - QA Manager
- **Gabriel Esteban Gutiérrez Calderón** (20221020003) - MLOps Developer
- **Jean Paul Contreras Talero** (20242020131) - Data Analyst

**Instructor**: [Professor Name]  
**Institution**: Universidad Distrital Francisco José de Caldas  
**Course**: Systems Analysis and Design  
**Program**: Computer Engineering  
**Semester**: 2024-2

---

## 🎓 Academic Context

### Course Objectives Achieved

1. ✅ **Systems Analysis**
   - Decompose complex systems into elements and relationships
   - Identify emergent behaviors and nonlinear dynamics
   - Apply chaos theory to real-world domains

2. ✅ **Architecture Design**
   - Translate requirements into implementable architectures
   - Apply design principles (modularity, coupling, cohesion)
   - Evolve designs based on feedback and constraints

3. ✅ **Quality Management**
   - Align with international standards (ISO, CMMI, Six Sigma)
   - Define measurable quality objectives and KPIs
   - Implement continuous improvement processes

4. ✅ **Risk Management**
   - Systematic identification of threats and vulnerabilities
   - Prioritize risks by likelihood and impact
   - Design mitigation strategies with monitoring

5. ✅ **Project Management**
   - Apply Agile-Kanban hybrid methodology
   - Define roles, responsibilities, and timelines
   - Track progress with traceability tools

### Learning Reflections

**What We Learned**:
- Systems thinking reveals hidden interdependencies (aspect-elevation coupling)
- Chaos theory provides actionable uncertainty quantification
- Quality standards (ISO, CMMI) structure development processes
- Architecture evolves through iterative refinement (7 → 4 layers, ensemble → single model)
- Production systems require fault tolerance, not just accuracy
- **Simplicity is a feature**: Single LightGBM outperforms ensemble in deployment contexts

**Challenges Overcome**:
- Balancing ecological sensitivity with computational efficiency
- Translating theoretical chaos concepts into operational code
- Deciding between ensemble complexity vs. single-model simplicity
- Performance-cost trade-off analysis (ensemble vs. LightGBM only)
- Maintaining reproducibility across team members
- Aligning academic timelines with software development cycles

**Future Directions**:
- Multi-region validation (beyond Colorado)
- Temporal drift monitoring with seasonal retraining
- Integration with GIS platforms for real-time field predictions
- Ensemble vs single-model performance monitoring in production
- Explainability dashboards for non-technical stakeholders

---

## 📚 References

### Academic Papers

1. Lorenz, E. N. (1963). *Deterministic Nonperiodic Flow*. Journal of the Atmospheric Sciences, 20(2), 130–141.

2. Saltelli, A., et al. (2008). *Global Sensitivity Analysis: The Primer*. Wiley.

3. Blackard, J. A., & Dean, D. J. (1999). *Comparative accuracies of artificial neural networks and discriminant analysis in predicting forest cover types*. Computers and Electronics in Agriculture, 24(3), 131-151.

### Standards and Frameworks

4. International Organization for Standardization. (2015). *ISO 9000:2015 — Quality Management Systems — Fundamentals and Vocabulary*.

5. International Organization for Standardization. (2022). *ISO/IEC 27001:2022 — Information Security Management Systems*.

6. CMMI Institute. (2023). *CMMI® V2.0 Model Overview*. Software Engineering Institute, Carnegie Mellon University.

7. American Society for Quality (ASQ). (2022). *Six Sigma: A Complete Guide to the DMAIC Process*.

### Technical Documentation

8. Studer, G., Schmitz, S., & Stocker, C. (2020). *Towards CRISP-ML(Q): A Machine Learning Process Model with Quality Assurance Methodology*. arXiv:2003.05155.

9. Bass, L., Clements, P., & Kazman, R. (2012). *Software Architecture in Practice* (3rd ed.). Addison-Wesley.

10. Hohpe, G., & Woolf, B. (2003). *Enterprise Integration Patterns: Designing, Building, and Deploying Messaging Solutions*. Addison-Wesley.

---

## 📄 License

This academic work is shared under the **Creative Commons Attribution-NonCommercial 4.0 International (CC BY-NC 4.0)** license.

**You are free to**:
- Share — copy and redistribute the material
- Adapt — remix, transform, and build upon the material

**Under the following terms**:
- **Attribution** — Cite this work appropriately
- **NonCommercial** — Not for commercial purposes
- **Academic Integrity** — Do not plagiarize for your own coursework

---

## 📧 Contact

**Primary Contact**: Nicolás Martínez Pineda  
**Email**: [student email]  
**GitHub**: [@nikkaoyy](https://github.com/nikkaoyy)

**Institution**: Universidad Distrital Francisco José de Caldas  
**Course Website**: [Systems Analysis and Design Course Page]

---

## 🙏 Acknowledgments

- **Professor [Name]** for guidance on systems thinking and architecture design
- **Universidad Distrital** for providing academic resources and infrastructure
- **Kaggle Community** for the Forest Cover Type dataset
- **Open Source Contributors** to scikit-learn, XGBoost, LightGBM, FastAPI, and MLflow

---

## ⭐ Repository Value

This repository demonstrates:
- ✅ Systematic application of systems engineering to ML
- ✅ Theoretical rigor with practical implementation focus
- ✅ Cross-disciplinary integration (ecology + CS + management)
- ✅ Complete documentation from analysis to production
- ✅ Reproducible academic research practices

**If this helped your learning, please star the repository!**

---

**🔗 Implementation Code**: [Forest Type Prediction Repository](https://github.com/nikkaoyy/Forest-Type-Prediction)

**📚 Course Materials**: See `Workshops/` folder for complete PDF reports

**🎯 Project Status**: ✅ Complete (December 2024)
