![Logo](https://raw.githubusercontent.com/Mark-Kitur/mark_os/main/meta-myowndisto/recipe-core/psplash/files/logo.png)

Mark OS – Embedded Linux Learning Platform (Yocto + Custom Layers)
Mark OS is a structured learning project focused on understanding, customizing, and building embedded Linux systems using the Yocto Project.
This repository captures my learning journey, including configuration files, custom layers, build experiments, and documentation as I work toward full-stack embedded Linux and kernel development.

Project Goals (Learning Phase)
Develop a solid foundation in Yocto workflows
Understand layer structure, recipes, and image customization
Practice managing build configurations (local.conf, multiconfig, overrides)
Create and maintain a custom layer (meta-root_v1)
Build minimal and custom root filesystems for real hardware targets
Document the full end-to-end build pipeline
Prepare groundwork for later phases (kernel development, security modules, BSP work)

This repository grows as I progress through each learning milestone.

Repository Structure
mark_os/
├── README.md
├── build/
│   └── conf/
│       ├── local.conf
│       └── bblayers.conf
│
├── meta-root_v1/
│   ├── conf/
│   │   └── layer.conf
│   ├── recipes-core/
│   ├── recipes-apps/
│   └── README.md

What each directory is for
build/conf/
Contains the development local.conf and bblayers.conf used during learning and experimentation.
meta-root_v1/
My first custom Yocto layer. Includes early recipes, experiments, and image modifications.
docs/
Learning notes on Yocto internals, build flow, rootfs structure, and other recorded insights.
Current Focus Areas

During this phase, I’m concentrating on:

1. Layer Creation & Organization
Designing meta-root_v1 from scratch
Adding simple custom recipes
Extending images with extra packages
Understanding how BitBake parses and resolves tasks
2. Build Configuration
Editing and tuning local.conf
Adding/remove layers
Managing different MACHINE targets
Exploring features such as:
image types
rootfs options
compression
package formats
build performance


Documenting everything I learn to build a strong foundation for future phases:

Yocto architecture
Recipe anatomy
How tasks execute
Rootfs generation
Image building pipeline
Build Instructions (Learning Mode)

These steps reflect my current learning workflow.
They will evolve as the project matures.

1. Source environment
source oe-init-build-env build
2. Ensure layer is included

Check bblayers.conf to confirm:

${TOPDIR}/../meta-root_v1 \
3. Build a target image

Example:

bitbake core-image-minimal
4. Output artifacts

After a successful build:

build/tmp/deploy/images/<machine>/

The documentation grows as I proceed through the roadmap.
Roadmap (Learning Phase Preview)
Complete Yocto fundamentals
Rebuild full pipeline from scratch
Set up hash equivalence server
Work on kernel configuration + modules
Add real projects (robotics, perception stack, services)
Explore Linux security modules (final stage)
Status

This repository is in active learning and experimentation mode.
Expect iterative improvements, refactoring, and documentation updates as I master each subsystem.
